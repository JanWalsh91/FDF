/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_v_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:10:12 by jwalsh            #+#    #+#             */
/*   Updated: 2017/03/18 16:03:01 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Returns a new vector which is the application of matrix m on vector v.
*/

t_vec3	m_v_mult(t_vec3 v, t_matrix m)
{
	t_vec3	new;

	new.x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0];
	new.y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1];
	new.z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2];
	return (new);
}
