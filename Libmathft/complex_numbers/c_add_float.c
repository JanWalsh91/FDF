/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_add_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:28:09 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/01 11:20:04 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Adds y to the real part of complex number x and z to its imaginary part.
** Returns the result.
*/

t_complex	c_add_float(t_complex x, double y, double z)
{
	t_complex res;

	res.r = x.r + y;
	res.i = x.i + z;
	return (res);
}
