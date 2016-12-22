/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fnct1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:40:03 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/22 15:08:03 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** Updates the position of the image to simulate a translation.
*/

void	update_img_pos_y(int i, t_env *e)
{
	mlx_clear_window(e->mlx, e->win.mlx);
	e->img.pos.y += i ;
	mlx_put_image_to_window(e->mlx, e->win.mlx, e->img.mlx, e->img.pos.x,
			e->img.pos.y);
}

void	update_img_pos_x(int i, t_env *e)
{
	mlx_clear_window(e->mlx, e->win.mlx);
	e->img.pos.x += i;
	mlx_put_image_to_window(e->mlx, e->win.mlx, e->img.mlx, e->img.pos.x,
			e->img.pos.y);
}

/*
** Updates the unit_size to simlate zooming in or out.
*/

void	update_unit_size(int i, t_env *e, t_data *d)
{
	t_pt2	old;
	t_pt2	new;
	int		frame;

	d->zoom += i;
	frame = (i < 0) ? -FRAME_WIDTH : FRAME_WIDTH;
	old.x = d->d2.max.x - d->d2.min.x;
	old.y = d->d2.max.y - d->d2.min.y;
	if (d->unit_size + d->zoom < 1)
	{
		d->zoom++;
		return ;
	}
	update_2d_coords(d);
	get_img_size(e, d);
	new.x = d->d2.max.x - d->d2.min.x;
	new.y = d->d2.max.y - d->d2.min.y;
	e->img.pos.x += (old.x - new.x) / 2;
	e->img.pos.y += (old.y - new.y) / 2;
	mlx_clear_window(e->mlx, e->win.mlx);
	mlx_destroy_image(e->mlx, e->img.mlx);
	e->img.mlx = mlx_new_image(e->mlx, e->img.w, e->img.h);
	update_image(d, e);
}

/*
** Resets the image position, zoom and matrices. Does not reset the color.
*/

void	recenter(t_env *e, t_data *d)
{
	d->zoom = 0;
	e->img.pos.x = 0;
	e->img.pos.y = 0;
	d->z_matrix = new_identity_matrix();
	d->matrix = new_identity_matrix();
	update_mpts3d(d);
	get_center(d);
	update_2d_coords(d);
	get_img_size(e, d);
	mlx_clear_window(e->mlx, e->win.mlx);
	mlx_destroy_image(e->mlx, e->img.mlx);
	e->img.mlx = mlx_new_image(e->mlx, e->img.w, e->img.h);
	update_image(d, e);
}
