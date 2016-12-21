/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fnct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:43:44 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/21 17:24:20 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	update_z_coord(int i, t_env *e, t_data *d)
{
	printf("----------------------------------------update_z_coord: %i\n", i);
	//t_matrix4	new;
	t_pt2		old;
	printf("check1\n");
	if (e->img.pos.y > -10000)
		d->matrix[2][2] *= (i > 0) ? 1.5 : 1 / 1.5;
	else
		d->matrix[2][2] *= (i > 0) ? 1 : 1 / 1.5;
	printf("new [2][2]: %.2f\n", d->matrix[2][2]);
	update_mpts3d(d);
	get_center(d);
	update_2d_coords(d);
	mlx_clear_window(e->mlx, e->win.mlx);
	mlx_destroy_image(e->mlx, e->img.mlx);
	old.y = e->img.h;
	old.x = e->img.w;
	get_d2(d);
	get_img_size(e, d);
	e->img.pos.y -= (-old.y + e->img.h);
	e->img.pos.x -= (-old.x + e->img.w);
	update_image(d, e);
}

void	rotate(char c, int i, t_env *e, t_data *d)
{
	t_matrix4	new;
	t_pt2	old;

	new = new_rotation_matrix(5 * i, c);
	d->matrix = matrix4_product(d->matrix, new);
	update_mpts3d(d);
	get_center(d);
	update_2d_coords(d);
	mlx_clear_window(e->mlx, e->win.mlx);
	mlx_destroy_image(e->mlx, e->img.mlx);
	old.y = e->img.h;
	old.x = e->img.w;
	get_d2(d);
	get_img_size(e, d);
	e->img.pos.y -= (-old.y + e->img.h) / 2;
	e->img.pos.x -= (-old.x + e->img.w) / 2;
	update_image(d, e);
}

void	update_colors(t_data *d, t_env *e)
{
	d->c++;
	(d->c == 4 + d->color_input) ? d->c = 0 : 0;
	mlx_clear_window(e->mlx, e->win.mlx);
	mlx_destroy_image(e->mlx, e->img.mlx);
	get_img_size(e, d);
	update_image(d, e);
}
