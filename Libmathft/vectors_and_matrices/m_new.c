/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:06:27 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/21 13:32:18 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Creates a new 4 by 4 matrix and sets its values to 0;
*/

t_matrix	m_new(void)
{
	int			x;
	int			y;
	t_matrix	m;

	if (!(m = (t_matrix)malloc(sizeof(double *) * 4)))
		return (m);
	y = -1;
	while (++y < 4)
	{
		if (!(m[y] = (double *)malloc(sizeof(double) * 4)))
			return (m);
		x = -1;
		while (++x < 4)
			m[y][x] = 0;
	}
	return (m);
}
