/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_polar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:22:38 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 16:23:48 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Transforms the complex number x.
*/

t_complex	c_polar(t_complex x)
{
	t_complex	res;
	double		r;
	double		t;

	t = atan(x.i / x.r);
	r = c_modulus(x);
	res.r = t / M_PI;
	res.i = r - 1;
	return (res);
}
