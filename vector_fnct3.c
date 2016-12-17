/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_fnct3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:50:09 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/10 15:47:34 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec3	 vec_translate(t_vec3 vec, t_vec3 i)
{
	vec.x *= i.x;
	vec.y *= i.y;
	vec.z *= i.z;
	return (vec);
}

t_vec3	vec_scale(t_vec3 vec, t_vec3 i)
{
	vec.x *= i.x;
	vec.y *= i.y;
	vec.z *= i.z;
	return (vec);
}

t_vec3	vec_rotate()
{

}
