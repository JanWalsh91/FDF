/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_new_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:22:02 by jwalsh            #+#    #+#             */
/*   Updated: 2017/06/27 13:37:06 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

static t_matrix	m_rot_x(float angle);
static t_matrix	m_rot_y(float angle);
static t_matrix	m_rot_z(float angle);

/*
** Creates a new rotation matrix of angle 'angle' around axis 'axis'
*/

t_matrix		m_new_rotate(float angle, char axis)
{
	if (axis == 'x' || axis == 'X')
		return (m_rot_x(angle));
	else if (axis == 'y' || axis == 'Y')
		return (m_rot_y(angle));
	else if (axis == 'z' || axis == 'Z')
		return (m_rot_z(angle));
	return (0);
}

static t_matrix	m_rot_x(float angle)
{
	t_matrix	m;

	m = m_new();
	m[0][0] = 1;
	m[1][1] = cos(to_radian(angle));
	m[1][2] = sin(to_radian(angle));
	m[2][1] = -sin(to_radian(angle));
	m[2][2] = cos(to_radian(angle));
	return (m);
}

static t_matrix	m_rot_y(float angle)
{
	t_matrix	m;

	m = m_new();
	m[0][0] = cos(to_radian(angle));
	m[0][2] = -sin(to_radian(angle));
	m[1][1] = 1;
	m[2][0] = sin(to_radian(angle));
	m[2][2] = cos(to_radian(angle));
	return (m);
}

static t_matrix	m_rot_z(float angle)
{
	t_matrix	m;

	m = m_new();
	m[0][0] = cos(to_radian(angle));
	m[0][1] = sin(to_radian(angle));
	m[1][0] = -sin(to_radian(angle));
	m[1][1] = cos(to_radian(angle));
	m[2][2] = 1;
	return (m);
}
