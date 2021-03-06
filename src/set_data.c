/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:11:00 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/19 17:59:46 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** Sets the values of the 3D point array and the colors in data based on the
** input of the file.
*/

static int	set_3d_pt(t_data *d, t_pt2 *i);
static int	init_set_3d_pts(t_data *d);

int			init_set_data(t_data *d)
{
	d->to_free = d->s;
	if (!init_colors(d) ||
			!init_set_3d_pts(d) ||
			!init_set_mpts3d(d) ||
			!init_get_pts_2d(d) ||
			!init_set_palettes(d))
		return (0);
	get_center(d);
	get_unit_size(d);
	update_2d_coords(d);
	return (1);
}

static int	init_set_3d_pts(t_data *d)
{
	t_pt2	j;
	t_pt2	i;

	i.x = 0;
	i.y = 0;
	if (!(d->pts_3d = (t_vec3 **)malloc(sizeof(t_vec3 *) * d->ref.y)))
		return (return_error());
	j.y = 0;
	while (j.y < d->ref.y)
	{
		if (!(d->pts_3d[j.y] = (t_vec3 *)malloc(sizeof(t_vec3) * d->ref.x)))
			return (return_error());
		j.x = 0;
		while (j.x < d->ref.x)
		{
			if (!(set_3d_pt(d, &i)))
				return (0);
			++j.x;
		}
		++j.y;
	}
	return (1);
}

/*
** Sets the coordinates of a point in the 3D cooridinate array based on the
** input.
** If a color is indicated, also sets the color at the appropriate cooridinate.
*/

static int	set_3d_pt(t_data *d, t_pt2 *i)
{
	if (!*(d->s) || *(d->s) == '\n')
		return (1);
	d->pts_3d[i->y][i->x].x = i->x;
	d->pts_3d[i->y][i->x].y = i->y;
	if (ft_isdigit(*d->s) || *d->s == '-' || *d->s == ',' || *d->s == ' ')
		d->pts_3d[i->y][i->x].z = ft_atoi(d->s);
	else
		return (ft_error("Invalid coordinate value"));
	while (*d->s == '-' || ft_isdigit(*d->s))
		++d->s;
	if (*d->s == ',')
		if ((d->colors[0][i->y][i->x] = set_color(&d->s)) == -1)
			return (ft_error("Color incorrectly formatted"));
	while (*d->s == 32 || *d->s == '\n')
		++d->s;
	increment_index(&i->x, &i->y, d);
	return (1);
}

/*
** Increment the x, y indices to iterate through the coords in either the 2D
** or 3D list.
*/

void		increment_index(int *x, int *y, t_data *data)
{
	(*x)++;
	if (*x == data->ref.x)
	{
		*x = 0;
		(*y)++;
	}
}
