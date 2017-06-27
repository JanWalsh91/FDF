/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fnct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:43:44 by jwalsh            #+#    #+#             */
/*   Updated: 2017/06/27 13:38:58 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** Changes updates the z_matrix to change the height of the map.
** The z_matrix is evaluated before the other matrix (for roations).
*/

void	update_z_coord(int i, t_env *e, t_data *d)
{
	t_pt2	old;

	if (e->img.pos.y > -10000 && e->img.pos.x > -5000 && e->img.pos.x < 5000)
		d->z_matrix[2][2] *= (i > 0) ? 1.5 : 1 / 1.5;
	else
		d->z_matrix[2][2] *= (i > 0) ? 1 : 1 / 1.5;
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
	e->img.pos.x -= (-old.x + e->img.w) / 2;
	update_image(d, e);
}

/*
** Updates the matrix to take into account rotation.
*/

void	rotate(char c, int i, t_env *e, t_data *d)
{
	t_matrix	new;
	t_pt2		old;

	new = m_new_rotate(5.0 * (float)i, c);
	d->matrix = m_mult(d->matrix, new);
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

/*
** Goes to the next color palette.
*/

void	update_colors(t_data *d, t_env *e)
{
	d->c++;
	(d->c == 4 + d->color_input) ? d->c = 0 : 0;
	mlx_clear_window(e->mlx, e->win.mlx);
	mlx_destroy_image(e->mlx, e->img.mlx);
	get_img_size(e, d);
	update_image(d, e);
}

int		red_button_exit(int k, t_all *a)
{
	a = NULL;
	k = 0;
	exit(0);
	return (0);
}
