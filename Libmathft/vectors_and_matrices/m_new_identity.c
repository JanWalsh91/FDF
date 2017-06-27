/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_new_identity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:17:57 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/21 13:18:10 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Creates a new 4 by 4 identity matrix.
** Mulpitplying a matrix by an identity matrix does not modify it.
*/

t_matrix	m_new_identity(void)
{
	t_matrix	m;

	m = m_new();
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = 1;
	m[3][3] = 1;
	return (m);
}
