/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_horseshoe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:17:26 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 16:21:23 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Transforms the complex number x.
*/

t_complex	c_horseshoe(t_complex x)
{
	t_complex	res;
	double		r;
	double		t;

	t = atan(x.i / x.r);
	r = c_modulus(x);
	res.r = r * cos(t + r);
	res.i = r * sin(t + r);
	return (res);
}
