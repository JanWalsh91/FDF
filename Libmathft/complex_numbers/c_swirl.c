/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_swirl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:21:43 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 16:22:24 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Transforms the complex number x.
*/

t_complex	c_swirl(t_complex x)
{
	t_complex	res;
	double		r;
	double		t;

	t = atan(x.i / x.r);
	r = c_modulus(x);
	res.r = r * cos(2 * t);
	res.i = r * sin(2 * t);
	return (res);
}
