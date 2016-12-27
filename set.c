/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:17:49 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/27 14:40:36 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_2d_coords(t_data *d, t_vec2 *p, int x, int y);

/*
** Allocates memory to the array of 2D coords and sets the points based off
** the values of the 3D coordinates. Those values are MULTIPLIED BY UNIT_SIZE
** which is initally set to 1.
*/

int			init_get_pts_2d(t_data *data)
{
	int	y;
	int	x;

	if (!(data->pts_2d = (t_vec2 **)malloc(sizeof(t_vec2 *) * data->ref.y)))
		return (return_error());
	y = 0;
	while (y < data->ref.y)
	{
		if (!(data->pts_2d[y] = (t_vec2 *)malloc(sizeof(t_vec2) * data->ref.x)))
			return (return_error());
		x = 0;
		while (x < data->ref.x)
		{
			get_2d_coords(data, &(data->pts_2d[y][x]), x, y);
			x++;
		}
		y++;
	}
	get_d2(data);
	return (1);
}

/*
** Updates the 2D coordinates based on the 3C coordinates and mupliplies
** the values by unit_size.
*/

void		update_2d_coords(t_data *d)
{
	int	y;
	int	x;

	y = 0;
	while (y < d->ref.y)
	{
		x = 0;
		while (x < d->ref.x)
		{
			get_2d_coords(d, &(d->pts_2d[y][x]), x, y);
			x++;
		}
		y++;
	}
}

/*
** Determines the 2D coords of a point based of the corresponding 3D coords of
** the same point and the center of the canvas. MULTIPLIED BY UNIT SIZE.
*/

static void	get_2d_coords(t_data *d, t_vec2 *p, int x, int y)
{
	p->x = (d->pts_3d[y][x].x + d->pts_3d[y][x].y + d->center.x);
	p->y = (((d->pts_3d[y][x].y - d->pts_3d[y][x].x) * 0.5) -
		d->pts_3d[y][x].z + d->center.y);
	p->x *= d->unit_size;
	p->y *= d->unit_size;
}
