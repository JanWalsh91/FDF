/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:15:21 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 16:20:22 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Transforms the complex number x.
*/

t_complex	c_sphere(t_complex x)
{
	t_complex	res;
	double		s;

	s = c_modulus(x) * c_modulus(x);
	res.r = x.r / s;
	res.i = x.i / s;
	return (res);
}
