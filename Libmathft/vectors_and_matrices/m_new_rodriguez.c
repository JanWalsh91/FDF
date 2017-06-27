/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_new_rodriguez.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:18:18 by jwalsh            #+#    #+#             */
/*   Updated: 2017/03/18 16:05:51 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Calculates and returns the roation matrix from vector b to vector a.
*/

t_matrix	m_new_rodriguez(t_vec3 a, t_vec3 b)
{
	t_matrix	m;
	t_matrix	n;
	t_vec3		v;
	double		angle;
	int			i;

	v = v_norm(v_cross(a, b));
	angle = acos(v_dot(a, b) / ((v_length(a) * v_length(b))));
	n = m_new_identity();
	n[1][0] = v.z;
	n[2][0] = -v.y;
	n[0][1] = -v.z;
	n[2][1] = v.x;
	n[0][2] = v.y;
	n[1][2] = -v.x;
	m = m_add(m_scale(n, sin(angle)), m_new_identity());
	m = m_add(m, m_scale(m_mult(n, n), 1 - cos(angle)));
	i = -1;
	while (++i < 3)
	{
		m[3][i] = 0;
		m[i][3] = 0;
	}
	m[3][3] = 1;
	return (m);
}
