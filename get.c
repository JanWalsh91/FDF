/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:40:37 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/17 13:31:10 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 ** Updates the min and max values of the coordinates of the 3D point array.
 */

void	get_d3(t_data *d)
{
	int	y;
	int	x;

	printf("get_d3\n");
	reset_d3(&(d->d3));
	y = -1;
	while (++y < d->ref.y)
	{
		x = -1;
		while (++x < d->ref.x)
		{
			//printf("checking value at: (%f, %f, %f)\n", d->pts_3d[y][x].x, d->pts_3d[y][x].y, d->pts_3d[y][x].z);
			d->d3.max.x < d->pts_3d[y][x].x ?
				d->d3.max.x = d->pts_3d[y][x].x : 0;
			d->d3.max.y < d->pts_3d[y][x].y ?
				d->d3.max.y = d->pts_3d[y][x].y : 0;
			d->d3.max.z < d->pts_3d[y][x].z ?
				d->d3.max.z = d->pts_3d[y][x].z : 0;
			d->d3.min.x > d->pts_3d[y][x].x ?
				d->d3.min.x = d->pts_3d[y][x].x : 0;
			d->d3.min.y > d->pts_3d[y][x].y ?
				d->d3.min.y = d->pts_3d[y][x].y : 0;
			d->d3.min.z > d->pts_3d[y][x].z ?
				d->d3.min.z = d->pts_3d[y][x].z : 0;
		}
	}
	printf("(x, y, z) d3.min: (%.2f, %.2f, %.2f) d3.max: (%.2f, %.2f, %.2f)\n", d->d3.min.x, d->d3.min.y, d->d3.min.z, d->d3.max.x, d->d3.max.y, d->d3.max.z);
}

/*
 ** Updates the min and max values of the coordinates of the 2D point array.
 */

void	get_d2(t_data *d)
{
	int	y;
	int	x;

	printf("get_d2\n");
	reset_d2(&(d->d2));
	y = -1;
	while (++y < d->ref.y)
	{
		x = -1;
		while (++x < d->ref.x)
		{
			//printf("checking value at: (%i, %i)(%f, %f)\n", y, x, d->pts_2d[y][x].x, d->pts_2d[y][x].y);
			d->d2.max.x < d->pts_2d[y][x].x ?
				d->d2.max.x = d->pts_2d[y][x].x : 0;
			d->d2.max.y < d->pts_2d[y][x].y ?
				d->d2.max.y = d->pts_2d[y][x].y : 0;
			d->d2.min.x > d->pts_2d[y][x].x ?
				d->d2.min.x = d->pts_2d[y][x].x : 0;
			d->d2.min.y > d->pts_2d[y][x].y ?
				d->d2.min.y = d->pts_2d[y][x].y : 0;
		}
	}
	printf("(y, x) d2.min: (%.2f, %.2f) d2.max: (%.2f, %.2f)\n", d->d2.min.y, d->d2.min.x, d->d2.max.y, d->d2.max.x);
}

/*
 ** Gets the center of the canvas, which is the reference point from which
 ** the 2d cords are calucalted. 
 */

void	get_center(t_data *d)
{
	d->center.x = -d->d2.min.x + FRAME_WIDTH;
	d->center.y = -d->d2.min.y + FRAME_WIDTH;
	printf("center: (y, x) (%.2f, %.2f)\n", d->center.y, d->center.x);
}

t_incr	get_incr(t_vec2 p1, t_vec2 p2, int c1, int c2)
{
	t_incr	incr;
	t_vec2	diff;

	diff.x = p1.x - p2.x;
	diff.y = p1.y - p2.y;
	incr.steps = (fabs(diff.x) > fabs(diff.y)) ? fabs(diff.x) : fabs(diff.y);
	(!incr.steps) ? incr.steps = 1 : 0;
	incr.x = -diff.x / incr.steps;
	incr.y = -diff.y / incr.steps;
	get_color_incr(&incr, c1, c2, incr.steps);
	printf("step: %.2f, incr.x: %.2f, incr.y: %.2f\n", incr.steps, incr.x, incr.y);
	return (incr);
}

void	get_color_incr(t_incr *incr, int c1, int c2, float steps)
{
	printf("get_color_incr: c1: %x c2: %x\n", c1, c2);
	int		mask;

	mask = 0xFF;
	incr->b = ((c2 & mask) - (c1 & mask)) / steps;
	mask = mask << 8;
	incr->g = (((c2 & mask) - (c1 & mask)) / steps) / 0x100;
	mask = mask << 8;
	incr->r = (((c2 & mask) - (c1 & mask)) / steps) / 0x10000;
	printf("RGB: %f, %f. %f\n", incr->r, incr->g, incr->b);

	//printf("RGB: %f, %f. %f\n", r_incr, g_incr, b_incr);
	//return (b_incr + g_incr + r_incr);
}
