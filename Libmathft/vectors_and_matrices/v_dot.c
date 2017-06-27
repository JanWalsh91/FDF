/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_dot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:24:27 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/21 13:24:30 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

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

double	v_dot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x +
			vec1.y * vec2.y +
			vec1.z * vec2.z);
}
