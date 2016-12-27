/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:40:37 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/27 11:47:40 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** Updates the min and max values of the coordinates of the 3D point array.
*/

void	get_d3(t_data *d)
{
	int	y;
	int	x;

	reset_d3(&(d->d3));
	y = -1;
	while (++y < d->ref.y)
	{
		x = -1;
		while (++x < d->ref.x)
		{
			d->d3.max.x < d->mpts_3d[y][x].x ?
				d->d3.max.x = d->mpts_3d[y][x].x : 0;
			d->d3.max.y < d->mpts_3d[y][x].y ?
				d->d3.max.y = d->mpts_3d[y][x].y : 0;
			d->d3.max.z < d->mpts_3d[y][x].z ?
				d->d3.max.z = d->mpts_3d[y][x].z : 0;
			d->d3.min.x > d->mpts_3d[y][x].x ?
				d->d3.min.x = d->mpts_3d[y][x].x : 0;
			d->d3.min.y > d->mpts_3d[y][x].y ?
				d->d3.min.y = d->mpts_3d[y][x].y : 0;
			d->d3.min.z > d->mpts_3d[y][x].z ?
				d->d3.min.z = d->mpts_3d[y][x].z : 0;
		}
	}
}

/*
** Updates the min and max values of the coordinates of the 2D point array.
*/

void	get_d2(t_data *d)
{
	int	y;
	int	x;

	reset_d2(&(d->d2));
	y = -1;
	while (++y < d->ref.y)
	{
		x = -1;
		while (++x < d->ref.x)
		{
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
}

/*
** Gets the center of the canvas, which is the reference point from which
** the 2d cords are calucalted. 
*/

void	get_center(t_data *d)
{
	reset_center(&d->center);
	update_2d_coords(d);
	get_d2(d);
	d->center.x = -d->d2.min.x / (d->unit_size + d->zoom) + FRAME_WIDTH;
	d->center.y = -d->d2.min.y / (d->unit_size + d->zoom) + FRAME_WIDTH;
}

/*
** Calculates the incrementation of x, y and the color for the line between
** two points.
*/

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
	return (incr);
}
