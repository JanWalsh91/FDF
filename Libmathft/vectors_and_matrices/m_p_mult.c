/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_p_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:10:58 by jwalsh            #+#    #+#             */
/*   Updated: 2017/03/18 16:01:33 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Returns the product of matrix m and vector p, with vector p treated as as
** point (applies translation).
*/

t_vec3	m_p_mult(t_vec3 p, t_matrix m)
{
	t_vec3	new;

	new.x = p.x * m[0][0] + p.y * m[1][0] + p.z * m[2][0] + m[0][3];
	new.y = p.x * m[0][1] + p.y * m[1][1] + p.z * m[2][1] + m[1][3];
	new.z = p.x * m[0][2] + p.y * m[1][2] + p.z * m[2][2] + m[2][3];
	return (new);
}
