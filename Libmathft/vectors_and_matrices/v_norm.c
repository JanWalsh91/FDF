/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_norm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:16:25 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/21 14:29:40 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Returns the normal of vector vec.
*/

t_vec3	v_norm(t_vec3 v)
{
	double	len;

	len = v_length(v);
	if (len > 0)
	{
		v.x *= 1 / len;
		v.y *= 1 / len;
		v.z *= 1 / len;
	}
	return (v);
}
