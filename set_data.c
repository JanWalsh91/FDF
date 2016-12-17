/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:11:00 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/17 15:48:09 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Sets the values of the 3D point array and the colors in data based on the
** input of the file.
*/

int	set_data(t_data *d)
{
	printf("set_data\n");
	t_pt2	j;
	t_pt2	i;
	
	set_colors(d);
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
			if (!(set_pt(d, &i)))
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

int	set_pt(t_data *data, t_pt2 *i)
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
		if (0 > (data->colors[0][i->y][i->x] = get_color(&data->s)))
			return (0);
		printf("Added color at (y, x) (%i, %i)\n", i->y, i->x);
	}
	while (*data->s == 32 || *data->s == '\n')
		++data->s;
	increment_index(&i->x, &i->y, data);
	return (1);
}

/*
** Extracts the color from the s string and returns its value in base 10.
*/

int	get_color(char **s)
{
	int		i;
	char	*tmp;

	printf("get_color\n");
	(*s)++;
	if ((*s)[0] != '0' || (*s)[1] != 'x')
		return (ft_error("Color incorrectly formatted"));
	(*s) += 2;
	i = 0;
	while ((*s)[i] && (*s)[i] != ' ' && (*s)[i] != '\n')
	{
		if (!((ft_isdigit((*s)[i])) || ('a' <= (*s)[i] && (*s)[i] <= 'f') ||
			('A' <= (*s)[i] && (*s)[i] <= 'F')))
			return (ft_error("Color incorrectly formatted"));
		++i;
	}
	if (!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
		return (error());
	tmp[i] = '\0';
	i = 0;
	while (**s && **s != ' ' && **s != '\n')
		tmp[i++] = *((*s)++);
	return (get_hex(tmp, i));
}

/*
** Gets the value of a int in base 16 in base 10.
*/

int	get_hex(char *tmp, int length)
{
	int	result;
	int	i;

	//printf("get_hex: %s\n", tmp);
	i = 0;
	result = 0;
	while (i < length)
	{
		result += get_hex_value(tmp[i++]);
		(i < length) ? result *= 16 : 0;
	}
	//printf("new color: %i\n", result);
	return (result);
}

/*
** Returns the value of a digit or character in base 16.
*/

int	get_hex_value(char c)
{
	int	i;

	if (ft_isdigit(c))
		i = c - '0';
	else if ('A' <= c && c <= 'F')
		i = c -'A' + 10;
	else
		i = 0;
	return (i);
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
