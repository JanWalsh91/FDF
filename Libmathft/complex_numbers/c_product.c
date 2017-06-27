/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_product.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:29:25 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/21 15:30:08 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Calculates and returns the product of complex numbers x and y.
*/

t_complex	c_product(t_complex x, t_complex y)
{
	t_complex res;

	res.r = (x.r * y.r) - (x.i * y.i);
	res.i = (x.r * y.i) + (x.i * y.r);
	return (res);
}
