/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:11:00 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/08 17:58:18 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Sets the values of the points in the 2D array of t_pts.
*/

int	set_data(t_pt ****pts, char *s, t_max max)
{
	int	y;
	int	x;
	
	printf("set_data\n");
	if (!((*pts) = (t_pt ***)malloc(sizeof(t_pt **) * (max.y + 1))))
		return (error());
	printf("malloc check1\n");
	(*pts)[max.y] = NULL;
	y = 0;
	while (y < max.y)
	{
		if (!((*pts)[y] = (t_pt **)malloc(sizeof(t_pt *) * (max.x + 1))))
			return (error());
		printf("malloc check2\n");
		(*pts)[y][max.x] = NULL;
		x = 0;
		while (x < max.x)
		{
			if (!(set_pt((*pts)[y] + x, &s)))
				return (error());
			x++;
		}
		s++;
		y++;
	}
	return (1);
}

int	set_pt(t_pt **pt, char **s)
{
	int		i;
	t_pt	new;

	printf("set_pt\n");
	if (!**s || **s == '\n')
	{
		new.z = 0;
		new.color = 0;
		(*pt) = &new;
		return (1);
	}
	i = 0;
	new.z = ft_atoi(*s);
	printf("found point: %i\n", new.z);
	while (ft_isdigit(**s))
		(*s)++;
	if (**s == ',')
	{
		new.color = get_color(s);
	}
	else
		new.color = 0;
	(*pt) = &new;
	(*s)++;
	return (1);
}

int	get_color(char **s)
{
	int		i;
	char	*tmp;

	printf("get_color\n");
	i = 0;
	while ((*s)[i] && (*s)[i] != ' ' && (*s)[i] != '\n')
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
		return (error());
	tmp[i] = '\0';
	i = 0;
	while (**s && **s != ' ' && **s != '\n')
		tmp[i++] = *((*s)++);
	return (get_hex(tmp));
}

int	get_hex(char *tmp)
{
	int length;
	int	result;
	int	i;

	i = 1;
	result = 0;
	if (tmp[0] != '0' || tmp [1] != 'x')
		return (0);
	tmp += 2;
	length = ft_strlen(tmp);
	while (length >= 0)
	{
		result *= get_value(tmp[length--]) * i;
		i *= 16;
	}
	return (result);
}

int	get_value(char c)
{
	int	i;

	if (ft_isdigit(c))
		i = c - '0';
	else if ('A' <= c && c <= 'F')
		i = c - 'A' + 10;
	else
		c = 0;
	return (c);
}
