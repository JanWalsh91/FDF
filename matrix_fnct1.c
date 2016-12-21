/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_fnct1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:47:45 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/21 16:12:02 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/vec.h"

/*
** Creates a new 4 by 4 matrix and sets its values to 0;
*/

t_matrix4	new_matrix(void)
{
	int			x;
	int			y;
	t_matrix4	m;

	if (!(m = (t_matrix4)malloc(sizeof(float *) * 4)))
		return (m);
	x = 0;
	while (x < 4)
	{
		if (!(m[x] = (float *)malloc(sizeof(float) * 4)))
			return (m);
		y = 0;
		while (y < 4)
		{
			m[x][y] = 0;
			++y;
		}
		++x;
	}
	return (m);
}

/*
** Creates a new 4 by 4 identity matrix.
** Mulpitplying a matrix by an identity matrix does not modify it.
*/

t_matrix4	new_identity_matrix(void)
{
	t_matrix4	m;

	m = new_matrix();
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = 1;
	return (m);
}

/*
** Creates a new scaling matrix which will scale a matrix or vector of all
** coordinates by i.
*/

t_matrix4	new_scaling_matrix(float i)
{
	t_matrix4	m;

	m = new_matrix();
	m[0][0] = i;
	m[1][1] = i;
	m[2][2] = i;
	return (m);
}

/*
** Combines two matrices.
*/

t_matrix4	matrix4_product(t_matrix4 m1, t_matrix4 m2)
{
	int			x;
	int			y;
	t_matrix4	m;

	m = new_matrix();
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			m[x][y] = m1[x][0] * m2[0][y] + 
				m1[x][1] * m2[1][y] + 
				m1[x][2] * m2[2][y] + 
				m1[x][3] * m2[3][y];
			++y;
		}
		++x;
	}
	return (m);
}

/*
** Returns a new vector which is the product of the matrix on the vector.
*/

t_vec3	vec3_matrix4_product(t_vec3 p, t_matrix4 m)
{
	t_vec3	new;

	new.x = p.x * m[0][0] + p.y * m[1][0] + p.z * m[2][0] + m[3][0];
	new.y = p.x * m[0][1] + p.y * m[1][1] + p.z * m[2][1] + m[3][1];
	new.z = p.x * m[0][2] + p.y * m[1][2] + p.z * m[2][2] + m[3][2];
	return (new);

}
