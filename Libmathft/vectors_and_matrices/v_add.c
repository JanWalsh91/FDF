/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:24:09 by jwalsh            #+#    #+#             */
/*   Updated: 2017/03/18 16:02:17 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Returns the sum of vec1 and vec2.
*/

t_vec3	v_add(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	vec.z = vec1.z + vec2.z;
	return (vec);
}
