/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:19:07 by jwalsh            #+#    #+#             */
/*   Updated: 2017/03/18 15:58:10 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Adds two matrices together.
*/

t_matrix	m_add(t_matrix m1, t_matrix m2)
{
	int			y;
	int			x;
	t_matrix	m;

	m = m_new_identity();
	y = -1;
	while (++y < 3)
	{
		x = -1;
		while (++x < 3)
			m[y][x] = m1[y][x] + m2[y][x];
	}
	return (m);
}
