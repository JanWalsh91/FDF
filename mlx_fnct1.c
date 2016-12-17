/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fnct1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:22:26 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/17 14:17:15 by jwalsh           ###   ########.fr       */
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

	set_palettes(data);
	get_center(data);
	update_2d_coords(data);
	printf("mlx_new_image with: (w, h) : (%i, %i)\n", e->img.w, e->img.h);
	e->img.mlx = mlx_new_image(e->mlx, e->img.w, e->img.h + 10);
	draw_image(data, e);
	printf("mlx_new_window with: (w, h): (%i, %i)\n", e->win.w, e->win.h);
	e->win.mlx = mlx_new_window(e->mlx, e->win.w, e->win.h, input);
	printf("mlx_put_image_to_window\n");
	mlx_put_image_to_window(e->mlx, e->win.mlx, e->img.mlx, 0, 0);
	printf("mlx_destroy_image\n");
	mlx_destroy_image(e->mlx, e->img.mlx);
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
** Calls on draw_line between each relevant 2D point.
*/

void	draw_image(t_data *d, t_env *e)
{
	t_pt2	i;

	printf("draw_image\n");
	e->draw.image = mlx_get_data_addr(e->img.mlx, &(e->draw.bpp),
			&(e->draw.size_line), &(e->draw.endian));
	put_2d_to_scale(d);
	i.y = 0;
	while (i.y < d->ref.y)
	{
		i.x = 0;
		while (i.x < d->ref.x)
		{
			(i.x + 1 != d->ref.x) ? draw_line(e,
				d->pts_2d[i.y][i.x],
				d->pts_2d[i.y][i.x + 1],
				d->colors[d->c][i.y][i.x],
				d->colors[d->c][i.y][i.x + 1]) : 0;
			(i.y + 1 != d->ref.y) ? draw_line(e,
				d->pts_2d[i.y][i.x],
				d->pts_2d[i.y + 1][i.x],
				d->colors[d->c][i.y][i.x],
				d->colors[d->c][i.y + 1][i.x]) : 0;
			++i.x;
		}
		++i.y;
	}
}

/*
** Determines the pixels that need to be drawn between two 2D pts.
*/

void	draw_line(t_env *e, t_vec2 p1, t_vec2 p2, int c1, int c2)
{
	printf("draw_line between (y, x) (%.2f, %.2f) and (%.2f, %.2f)\n", p1.y, p1.x, p2.y, p2.x);
	t_incr	incr;
	t_vec2	pt;
	float	color;
	int		v;

	incr = get_incr(p1, p2, c1, c2);
	v = 0;
	pt.x = p1.x;
	pt.y = p1.y;
	color = c1;
	while (v < incr.steps)
	{
		//color += incr.color;
		//printf("new pixel: pt.y, pt.x: (%.2f, %.2f)\n", pt.y, pt.x);
		draw_pixel(e, ft_round(pt.x), ft_round(pt.y),
				color +
				ft_round(incr.r * v) * 0x10000 +
				ft_round(incr.g * v) * 0x100 +
				ft_round(incr.b * v));
		pt.x += incr.x;
		pt.y += incr.y;
		++v;
		//color = color + incr. * v;
		//color += incr.color;
		//++v;
	}
	printf("end draw_line\n");
}

/*
** Puts one pixel to the image at coordinate x, y.
*/

void	draw_pixel(t_env *e, int x, int y, int color)
{
	printf("draw_pixel at (y, x): (%i, %i) with color: %x\n", y, x, color);
	e->draw.tmp = (unsigned int *)(e->draw.image + y*e->draw.size_line +
			x * e->draw.bpp / 8);
	*(e->draw.tmp) = color;
	printf("end draw_pixel\n");
}

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

