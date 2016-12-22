/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:08:38 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/22 16:57:38 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** Controls the MLX flow by reacting to user input after read the file and
** setting the data.
*/

static int	my_key_fnct(int keycode, t_all *a);
static int	my_mouse_hook(int button, int x, int y, t_all *a);

void	fdf(char *input)
{
	t_all	a;

	set_default_values(&a.d, &a.e);
	if (!read_file(input, &a.d) || !init_set_data(&a.d))
		return ;
	a.e.mlx = mlx_init();
	init_window(&a.d, &a.e, input);
	update_instructions(&a.e, 1);
	mlx_mouse_hook(a.e.win.mlx, &my_mouse_hook, &a);
	mlx_hook(a.e.win.mlx, KEYPRESS, KEYPRESSMASK, &my_key_fnct, &a);
	mlx_loop(a.e.mlx);
}

/*
** Responds to user keyboard input.
*/

static int	my_key_fnct(int k, t_all *a)
{
	if (k == KEY_ESCAPE)
		exit(0);
	else if (k == KEY_UP || k == KEY_DOWN)
		update_img_pos_y(k == KEY_UP ? -5 : 5, &(a->e));
	else if (k == KEY_RIGHT || k == KEY_LEFT)
		update_img_pos_x(k == KEY_LEFT ? -5 : 5, &(a->e));
	else if (k == KEY_SPACE)
		recenter(&(a->e), &(a->d));
	else if (k == KEY_EQUAL || k == KEY_PAD_ADD ||
			k == KEY_MINUS || k == KEY_PAD_SUB)
		update_unit_size(k == KEY_EQUAL || k == KEY_PAD_ADD ?
				1 : -1, &(a->e), &(a->d));
	else if (k == KEY_OPEN_BRACE || k == KEY_CLOSE_BRACE)
		update_z_coord(k == KEY_OPEN_BRACE ? -1 : 1, &(a->e), &(a->d));
	else if (k == KEY_Q || k == KEY_A)
		rotate('z', k == KEY_Q ? 1 : -1, &a->e, &a->d);
	else if (k == KEY_W || k == KEY_S)
		rotate('x', k == KEY_W ? 1 : -1, &a->e, &a->d);
	else if (k == KEY_E || k == KEY_D)
		rotate('y', k == KEY_E ? 1 : -1, &a->e, &a->d);
	else if (k == KEY_C)
		update_colors(&a->d, &a->e);
	update_instructions(&a->e, 0);
	return (k);
}

/*
** Responds to user mouse clicks.
*/

static int	my_mouse_hook(int button, int x, int y, t_all *a)
{
	printf("button: %i\n", button);
	if (!x || y < 1)
		return (0);
	if (button == 1)
	{
		mlx_clear_window(a->e.mlx, a->e.win.mlx);
		mlx_put_image_to_window(a->e.mlx, a->e.win.mlx, a->e.img.mlx,
			a->e.img.pos.x, a->e.img.pos.y);
		update_instructions(&a->e, 1);
		return (0);
	}
	if (button == 4)
		update_unit_size(1, &a->e, &a->d);
	if (button == 5)
		update_unit_size(-1, &a->e, &a->d);
	update_instructions(&a->e, 0);
	return (0);
}
