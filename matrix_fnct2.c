/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_fnct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:54:01 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/17 12:42:47 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

static t_matrix4	m_rot_x(float angle);
static t_matrix4	m_rot_y(float angle);
static t_matrix4	m_rot_z(float angle);

/*
** Combines a matrix and a translation vector.
*/

t_matrix4	matrix4_translation(t_matrix4 m, t_vec3 v)
{
	m[0][3] += v.x;
	m[1][3] += v.y;
	m[2][3] += v.z;
	return (m);
}

/*
** Creates a new rotation matrix of angle 'angle' around axis 'axis'
*/

t_matrix4	new_rotation_matrix(float angle, char axis)
{
	if (axis == 'x' || axis == 'X')
		return (m_rot_x(angle));
	else if (axis == 'y' || axis == 'Y')
		return (m_rot_y(angle));
	else if (axis == 'z' || axis == 'Z')
		return (m_rot_z(angle));
	return (0);
}

static t_matrix4	m_rot_x(float angle)
{
	t_matrix4	m;

	m = new_matrix();
	m[0][0] = 1;
	m[1][1] = cos(to_radian(angle));
	m[1][2] = sin(to_radian(angle));
	m[2][1] = -sin(to_radian(angle));
	m[2][2] = cos(to_radian(angle));
	return (m);
}

static t_matrix4	m_rot_y(float angle)
{
	t_matrix4	m;

	m = new_matrix();
	m[0][0] = cos(to_radian(angle));
	m[0][2] = -sin(to_radian(angle));
	m[1][1] = 1;
	m[2][0] = sin(to_radian(angle));
	m[2][2] = cos(to_radian(angle));
	return (m);
}

static t_matrix4	m_rot_z(float angle)
{
	t_matrix4	m;

	m = new_matrix();
	m[0][0] = cos(to_radian(angle));
	m[0][1] = sin(to_radian(angle));
	m[1][0] = -sin(to_radian(angle));
	m[1][1] = cos(to_radian(angle));
	m[2][2] = 1;
	return (m);
}

