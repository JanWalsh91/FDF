/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_fnct1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:06:54 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/10 16:54:16 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

float	vec_length(t_vec3 vec)
{
	return (sqrt(vec_dot(vec, vec)));
}

t_vec3	vec_normalize(t_vec3 vec)
{
	float len;

	len = vec_length(vec);
	if (len > 0)
	{
		vec.x *= 1/len;
		vec.y *= 1/len;
		vec.z *= 1/len;
	}
	return (vec);
}

/*
** The dot product of two vectors relates to the cosine of the angle between
** the two vectors.
**
** If B is a unit vector, then the product A.B gives ||A||cos(a), The
** magnitude of the projection of A in teh direction of B, with a minus
** sign if the direction is opposite.
**
** When neither A nor B is a unit vector, get the unit vector of one of The
** vectors: A.B/||B||.
**
** When both vectors are normalized, taking the arc cosine of the dot product
** gives you the angle a between the two vectors. (acos(x), x in radians)
*/

float	vec_dot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x +
			vec1.y * vec2.y +
			vec1.z * vec2.y);
}

/*
** The cross products of two vectors results in a vector orthognoal to the
** plane produced by those two vectors.
** This is useful to create a Cartesian Coordinate system.
*/

t_vec3	vec_cross_product(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3 vec;

	vec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	vec.y = vec1.z * vec2.x - vec1.x * vec2.z;
	vec.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (vec);
}

double to_radian(double a)
{
	return (a * M_PI / 180);
}
