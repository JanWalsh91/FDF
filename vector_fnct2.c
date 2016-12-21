/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_fnct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:27:49 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/10 16:53:47 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/vec.h"

t_vec3	vec_plus(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;
			
	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	vec.z = vec1.z + vec2.z;
	return (vec);
}

t_vec3	vec_minus(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	vec.z = vec1.z - vec2.z;
	return (vec);
}

t_vec3	vec_product(t_vec3 vec1, float i)
{
	t_vec3	vec;

	vec.x = vec1.x * i;
	vec.y = vec1.y * i;
	vec.z = vec1.z * i;
	return (vec);
}
