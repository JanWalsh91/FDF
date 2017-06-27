/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_clamp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:02:26 by jwalsh            #+#    #+#             */
/*   Updated: 2017/03/18 16:06:38 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libmathft.h"

/*
** Limits the values of the coords of a vec within the range of min and max.
*/

t_vec3	v_clamp(t_vec3 v, double min, double max)
{
	v.x < min ? v.x = min : 0;
	v.x > max ? v.x = max : 0;
	v.y < min ? v.y = min : 0;
	v.y > max ? v.y = max : 0;
	v.z < min ? v.z = min : 0;
	v.z > max ? v.z = max : 0;
	return (v);
}
