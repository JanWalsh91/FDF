/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:11:00 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/17 18:09:35 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Sets the values of the 3D point array and the colors in data based on the
** input of the file.
*/

static int	set_3d_pt(t_data *data, t_pt2 *i);

int	init_set_data(t_data *d)
{
	printf("set_data\n");
	t_pt2	j;
	t_pt2	i;
	
	i.x = 0;
	i.y = 0;
	if (!((d->pts_3d) = (t_vec3 **)malloc(sizeof(t_vec3 *) * d->ref.y)))
		return (error());
	j.y = 0;
	while (j.y < d->ref.y)
	{
		if (!(d->pts_3d[j.y] = (t_vec3 *)malloc(sizeof(t_vec3) * d->ref.x)))
			return (error());
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

static int	set_3d_pt(t_data *data, t_pt2 *i)
{
	printf("set_pt\n");
	if (!*(data->s) || *(data->s) == '\n')
		return (1);
	data->pts_3d[i->y][i->x].x = i->x;
	data->pts_3d[i->y][i->x].y = i->y;
	data->pts_3d[i->y][i->x].z = ft_atoi(data->s);
	while (ft_isdigit(*data->s))
		++data->s;
	if (*data->s == ',')
	{
		if (0 > (data->colors[0][i->y][i->x] = set_color(&data->s)))
			return (0);
		printf("Added color at (y, x) (%i, %i)\n", i->y, i->x);
	}
	while (*data->s == 32 || *data->s == '\n')
		++data->s;
	increment_index(&i->x, &i->y, data);
	return (1);
}

/*
** Increment the x, y indices to iterate through the coords in either the 2D
** or 3D list.
*/

void	increment_index(int *x, int *y, t_data *data)
{
	(*x)++;
	if (*x == data->ref.x)
	{
		*x = 0;
		(*y)++;
	}
}
