/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:22:58 by jwalsh            #+#    #+#             */
/*   Updated: 2017/03/18 16:03:36 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Creates and returns a new vector with values x, y, and z.
*/

t_vec3	v_new(double x, double y, double z)
{
	t_vec3	new_v;

	new_v.x = x;
	new_v.y = y;
	new_v.z = z;
	return (new_v);
}
