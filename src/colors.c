/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:19:48 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 15:44:35 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static int	get_hex(char *tmp, int length);
static int	get_hex_value(char c);

void		get_color_incr(t_incr *incr, int c1, int c2, float steps)
{
	int	mask;

	mask = 0xFF;
	incr->b = ((c2 & mask) - (c1 & mask)) / steps;
	mask = mask << 8;
	incr->g = (((c2 & mask) - (c1 & mask)) / steps) / 0x100;
	mask = mask << 8;
	incr->r = (((c2 & mask) - (c1 & mask)) / steps) / 0x10000;
}

/*
** Extracts the color from the s string and returns its value in base 10.
*/

int			set_color(char **s)
{
	int		i;
	char	*tmp;

	(*s)++;
	if ((*s)[0] != '0' || (*s)[1] != 'x')
		return (-1);
	(*s) += 2;
	i = 0;
	while ((*s)[i] && (*s)[i] != ' ' && (*s)[i] != '\n')
	{
		if (!((ft_isdigit((*s)[i])) || ('a' <= (*s)[i] && (*s)[i] <= 'f') ||
					('A' <= (*s)[i] && (*s)[i] <= 'F')))
			return (-1);
		++i;
	}
	if (!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
		return (return_error());
	tmp[i] = '\0';
	i = 0;
	while (**s && **s != ' ' && **s != '\n')
		tmp[i++] = *((*s)++);
	return (get_hex(tmp, i));
}

/*
** Gets the value of a int in base 16 in base 10.
*/

static int	get_hex(char *tmp, int length)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (i < length)
	{
		result += get_hex_value(tmp[i++]);
		(i < length) ? result *= 16 : 0;
	}
	free(tmp);
	return (result);
}

/*
** Returns the value of a digit or character in base 16.
*/

static int	get_hex_value(char c)
{
	int	i;

	if (ft_isdigit(c))
		i = c - '0';
	else if ('A' <= c && c <= 'F')
		i = c - 'A' + 10;
	else
		i = 0;
	return (i);
}
