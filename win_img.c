/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:26:52 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/22 13:09:24 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** Opens the window for the first time, draws and place the image on the
** window and destroys the image.
*/

void	init_window(t_data *d, t_env *e, char *input)
{
	//printf("init_window\n");
	get_win_size(e, d);
	e->win.mlx = mlx_new_window(e->mlx, e->win.w, e->win.h, input);
	update_image(d, e);
}

/*
** Creates a new images and puts it on the window.
*/

void	update_image(t_data *d, t_env *e)
{
	//printf("update_image: (w, h) : (%i, %i)\n", e->img.w, e->img.h);
	e->img.mlx = mlx_new_image(e->mlx, e->img.w, e->img.h);
	draw_image(d, e);
	//printf("mlx_put_image_to_window at (y, x) (%i, %i)\n", e->img.pos.y, e->img.pos.x);
	mlx_put_image_to_window(e->mlx, e->win.mlx, e->img.mlx, e->img.pos.x,
			e->img.pos.y);
}

/*
** Determines the initial window dimensions based off initial img dimensions.
*/

void	get_win_size(t_env *e, t_data *d)
{
	get_img_size(e, d);
	e->win.h = e->img.h;
	e->win.w = e->img.w;
}

/*
** Determines the size of the image to create based on unit_size and zoom.
*/

void	get_img_size(t_env *e, t_data *d)
{
	float	height;
	float	width;

	get_d2(d);
	//printf("get_img_size\n");
	height = d->d2.max.y - d->d2.min.y;
	width = d->d2.max.x - d->d2.min.x;
	e->img.h = height + FRAME_WIDTH * 2 * (d->unit_size + d->zoom);
	e->img.w = width + FRAME_WIDTH * 2 * (d->unit_size + d->zoom);
	//printf("height: %.2f, width: %.2f\n", height, width);
}

/*
** Updates the 2d min max.
** Updates the unit size based on the 2d min max, MAX_UNIT_SIZE, MAX_WIN_H,
** MAX_WIN_W, MIN_WIN_H and MIN_WIN_W.
*/

void	get_unit_size(t_data *d)
{
	float	height;
	float	width;

	get_d2(d);
	height = d->d2.max.y - d->d2.min.y;
	width = d->d2.max.x - d->d2.min.x;
	d->unit_size = ((height + FRAME_WIDTH * 2) * MAX_UNIT_SIZE > MAX_WIN_H) ?
		MAX_WIN_H / (height + FRAME_WIDTH * 2) : MAX_UNIT_SIZE;
	d->unit_size = ((width + FRAME_WIDTH * 2) * d->unit_size > MAX_WIN_W) ?
		MAX_WIN_W / (width + FRAME_WIDTH * 2) : d->unit_size;
	d->unit_size = ((height + FRAME_WIDTH * 2) * d->unit_size < MIN_WIN_H) ?
		MIN_WIN_H / (height + FRAME_WIDTH * 2) : d->unit_size;
	d->unit_size = ((width + FRAME_WIDTH * 2) * d->unit_size < MIN_WIN_W) ?
		MIN_WIN_W / (width + FRAME_WIDTH * 2) : d->unit_size;
}
