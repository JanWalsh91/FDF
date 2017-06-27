/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_isnan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:25:01 by jwalsh            #+#    #+#             */
/*   Updated: 2017/03/18 16:03:16 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Checks if a vector's coordinates are numbers.
** Returns 1 if all coords are NAN.
*/

int	v_isnan(t_vec3 v)
{
	return (isnan(v.x) && isnan(v.y) && isnan(v.z));
}
