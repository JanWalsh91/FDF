/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:08:38 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/21 18:17:43 by jwalsh           ###   ########.fr       */
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
	//---MLX FLOW CONROL FUNCTIONS---
	update_instructions(&a.e, 1);
	printf("(%i, %i)\n", a.e.img.w, a.e.img.h);
	mlx_mouse_hook(a.e.win.mlx, &my_mouse_hook, &a);
	mlx_hook(a.e.win.mlx, KEYPRESS, KEYPRESSMASK, &my_key_fnct, &a);
	mlx_loop(a.e.mlx);
}

static int	my_key_fnct(int keycode, t_all *a)
{
	printf("my_key_fnct: %i\n", keycode);
	printf("(%i, %i)\n", a->e.img.w, a->e.img.h);
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
		update_img_pos_y(keycode == KEY_UP ? -5 : 5, &(a->e));
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		update_img_pos_x(keycode == KEY_LEFT ? -5 : 5, &(a->e));
	else if (keycode == KEY_SPACE)
		recenter(&(a->e), &(a->d));
	else if (keycode == KEY_EQUAL || keycode == KEY_MINUS)
		update_unit_size(keycode == KEY_EQUAL ? 1 : -1, &(a->e), &(a->d));
	else if (keycode == KEY_OPEN_BRACE || keycode == KEY_CLOSE_BRACE)
		update_z_coord(keycode == KEY_OPEN_BRACE ? -1 : 1, &(a->e), &(a->d));
	else if (keycode == KEY_Q || keycode == KEY_A)
		rotate('z', keycode == KEY_Q ? 1 : -1, &a->e, &a->d);
	else if (keycode == KEY_W || keycode == KEY_S)
		rotate('x', keycode == KEY_W ? 1 : -1, &a->e, &a->d);
	else if (keycode == KEY_E || keycode == KEY_D)
		rotate('y', keycode == KEY_E ? 1 : -1, &a->e, &a->d);
	else if (keycode == KEY_C)
		update_colors(&a->d, &a->e);
	update_instructions(&a->e, 0);
	return (keycode);
}

static int	my_mouse_hook(int button, int x, int y, t_all *a)
{
	x = 0;
	y = 0;
	printf("Check\n");
	mlx_clear_window(a->e.mlx, a->e.win.mlx);
	mlx_put_image_to_window(a->e.mlx, a->e.win.mlx, a->e.img.mlx,
			a->e.img.pos.x, a->e.img.pos.y);
	printf("Check\n");
	update_instructions(&a->e, 1);
	return (button);
}
