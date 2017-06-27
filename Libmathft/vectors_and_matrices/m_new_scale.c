/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_new_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:10:07 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/21 13:30:47 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Creates a new scaling matrix which will scale a matrix or vector of all
** coordinates by i.
*/

t_matrix	m_new_scale(double i)
{
	t_matrix	m;

	m = m_new_identity();
	m[0][0] = i;
	m[1][1] = i;
	m[2][2] = i;
	return (m);
}
