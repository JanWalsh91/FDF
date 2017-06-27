/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_mult.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:27:55 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/21 13:28:38 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Multiplies vector vec by vector i.
*/

t_vec3	v_mult(t_vec3 vec, t_vec3 i)
{
	vec.x *= i.x;
	vec.y *= i.y;
	vec.z *= i.z;
	return (vec);
}
