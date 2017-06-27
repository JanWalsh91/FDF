/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_product_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:09:31 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 17:10:24 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

t_complex	c_product_double(t_complex x, double y)
{
	t_complex	res;

	res.r = x.r * y;
	res.i = x.i * y;
	return (res);
}
