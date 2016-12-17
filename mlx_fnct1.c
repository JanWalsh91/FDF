/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fnct1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:22:26 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/17 18:05:20 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Opens the window for the first time, draws and place the image on the
** window and destroys the image.
*/

int		init_window(t_data *data, t_env *e, char *input)
{
	printf("init_window\n");

	if (!(init_pts_2d(data)))
		return (0);
	get_init_win_size(e, data);
	get_d3(data);
	init_set_palettes(data);
	get_center(data);
	update_2d_coords(data);
	printf("mlx_new_image with: (w, h) : (%i, %i)\n", e->img.w, e->img.h);
	e->img.mlx = mlx_new_image(e->mlx, e->img.w, e->img.h);
	put_2d_to_scale(data);
	draw_image(data, e);
	printf("mlx_new_window with: (w, h): (%i, %i)\n", e->win.w, e->win.h);
	e->win.mlx = mlx_new_window(e->mlx, e->win.w, e->win.h, input);
	printf("mlx_put_image_to_window\n");
	mlx_put_image_to_window(e->mlx, e->win.mlx, e->img.mlx, 0, 0);
	return (1);
}

/*
** Determines the initial window height and width based on a MAX_UNIT_SIZE
** and the min max of the 2d coords.
*/

void	get_init_win_size(t_env *e, t_data *d)
{
	float	height;
	float	width;

	printf("get_init_win_size\n");
	height = d->d2.max.y - d->d2.min.y;
	width = d->d2.max.x - d->d2.min.x;
	d->unit_size = ((height + FRAME_WIDTH * 2) * MAX_UNIT_SIZE > MAX_WIN_H) ?
		MAX_WIN_H / (height + FRAME_WIDTH * 2) : MAX_UNIT_SIZE;
	d->unit_size = ((width + FRAME_WIDTH * 2) * d->unit_size > MAX_WIN_W) ?
		MAX_WIN_W / (width + FRAME_WIDTH * 2) : d->unit_size;
	e->img.h = (height + FRAME_WIDTH * 2) * d->unit_size;
	e->img.w = (width + FRAME_WIDTH * 2) * d->unit_size;
	printf("unit_size: %i\n", d->unit_size);
	e->win.h = e->img.h;
	e->win.w = e->img.w;
}

/*
** Multiplies the 2d coords by unit_size.
*/

void	put_2d_to_scale(t_data *d)
{
	int	y;
	int x;

	y = 0;
	while (y < d->ref.y)
	{
		x = 0;
		while (x < d->ref.x)
		{
			d->pts_2d[y][x].x *= d->unit_size;
			d->pts_2d[y][x].y *= d->unit_size;
			x++;
		}
		y++;
	}
}

