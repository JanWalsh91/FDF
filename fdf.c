/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:08:38 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/23 16:47:34 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static int	next_file(void *mlx, int file_count, char **file_names, int i);
static int	my_key_fnct(int keycode, t_all *a);
static int	my_key_fnct2(int k, t_all *a, int i);
static int	my_mouse_hook(int button, int x, int y, t_all *a);

/*
** Initilizes MLX and calls on the first file to be prepared.
*/

int		fdf(int file_count, char **file_names)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx || !(next_file(mlx, file_count, file_names, 0)))
		return (0);
	return (1);
}

/*
** Contains the MLX flow functions to prepare a file and responf to user input.
*/

static int	next_file(void *mlx, int file_count, char **file_names, int i)
{
	t_all		a;
	
	a.e.mlx = mlx;
	set_default_values(&a.d, &a.e, file_count, file_names, i);
	if (!read_file(file_names[i], &a.d) || !init_set_data(&a.d))
	{
		exit(0);
		return (0);
	}
	init_window(&a.d, &a.e, file_names[i]);
	update_instructions(&a.e, 0, file_count);
	mlx_mouse_hook(a.e.win.mlx, &my_mouse_hook, &a);
	mlx_hook(a.e.win.mlx, KEYPRESS, KEYPRESSMASK, &my_key_fnct, &a);
	mlx_hook(a.e.win.mlx, 17, (1L << 17), &red_button_exit, &a);
	mlx_loop(a.e.mlx);
	return (1);
}

/*
** Responds to user keyboard input.
*/

static int	my_key_fnct(int k, t_all *a)
{
	int	i;

	(!(i = 0) && k == KEY_ESCAPE) ? exit(0) : 0;
	if ((k == KEY_UP || k == KEY_DOWN) && (i = 1))
		update_img_pos_y(k == KEY_UP ? -5 : 5, &(a->e));
	else if ((k == KEY_RIGHT || k == KEY_LEFT) && (i = 1))
		update_img_pos_x(k == KEY_LEFT ? -5 : 5, &(a->e));
	else if (k == KEY_SPACE && (i = 1))
		recenter(&(a->e), &(a->d));
	else if ((k == KEY_EQUAL || k == KEY_PAD_ADD ||
			k == KEY_MINUS || k == KEY_PAD_SUB) && (i = 1))
		update_unit_size(k == KEY_EQUAL || k == KEY_PAD_ADD ?
				1 : -1, &(a->e), &(a->d));
	else if ((k == KEY_OPEN_BRACE || k == KEY_CLOSE_BRACE) && (i = 1))
		update_z_coord(k == KEY_OPEN_BRACE ? -1 : 1, &(a->e), &(a->d));
	else if ((k == KEY_Q || k == KEY_A) && (i = 1))
		rotate('z', k == KEY_Q ? 1 : -1, &a->e, &a->d);
	else if ((k == KEY_W || k == KEY_S) && (i = 1))
		rotate('x', k == KEY_W ? 1 : -1, &a->e, &a->d);
	else if ((k == KEY_E || k == KEY_D) && (i = 1))
		rotate('y', k == KEY_E ? 1 : -1, &a->e, &a->d);
	else if (k == KEY_C && (i = 1))
		update_colors(&a->d, &a->e);
	my_key_fnct2(k, a, !i ? 0 : 1);
	return (k);
}

static int	my_key_fnct2(int k, t_all *a, int i)
{
	if (k == KEY_LESS_THAN)
		if (a->d.file_index > 0 && (i = 1))
		{
			mlx_destroy_window(a->e.mlx, a->e.win.mlx);
			free_all(a);
			return (next_file(a->e.mlx, a->d.file_count, a->d.file_names,
					a->d.file_index - 1));
		}
	if (k == KEY_GREATER_THAN)
		if (a->d.file_index < a->d.file_count - 1 && (i = 1))
		{
			mlx_destroy_window(a->e.mlx, a->e.win.mlx);
			free_all(a);
			return (next_file(a->e.mlx, a->d.file_count, a->d.file_names,
					a->d.file_index + 1));
		}
	if (i == 1)
		update_instructions(&a->e, 0, a->d.file_count);
	return (0);
}

/*
** Responds to user mouse clicks.
*/

static int	my_mouse_hook(int button, int x, int y, t_all *a)
{
	if (!x || y < 1)
		return (0);
	if (button == 1)
	{
		mlx_clear_window(a->e.mlx, a->e.win.mlx);
		mlx_put_image_to_window(a->e.mlx, a->e.win.mlx, a->e.img.mlx,
			a->e.img.pos.x, a->e.img.pos.y);
		update_instructions(&a->e, 1, a->d.file_count);
		return (0);
	}
	if (button == 4)
		update_unit_size(1, &a->e, &a->d);
	if (button == 5)
		update_unit_size(-1, &a->e, &a->d);
	if (button == 1 || button == 4 || button == 5)
		update_instructions(&a->e, 0, a->d.file_count);
	return (0);
}
