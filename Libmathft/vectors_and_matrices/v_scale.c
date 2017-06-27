/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_scale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:25:08 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/21 14:30:01 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Scales a vector by i.
*/

t_vec3	v_scale(t_vec3 v, double i)
{
	t_vec3	vec;

	vec.x = v.x * i;
	vec.y = v.y * i;
	vec.z = v.z * i;
	return (vec);
}
