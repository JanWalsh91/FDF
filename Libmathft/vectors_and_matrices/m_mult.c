/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_mult.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:17:19 by jwalsh            #+#    #+#             */
/*   Updated: 2017/06/27 13:28:55 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Combines two matrices.
*/

t_matrix	m_mult(t_matrix m1, t_matrix m2)
{
	int			x;
	int			y;
	t_matrix	m;

	m = m_new();
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			m[y][x] = m1[y][0] * m2[0][x] +
				m1[y][1] * m2[1][x] +
				m1[y][2] * m2[2][x] +
				m1[y][3] * m2[3][x];
		}
	}
	return (m);
}
