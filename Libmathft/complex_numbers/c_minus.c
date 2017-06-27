/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_minus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 11:59:43 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/29 11:59:44 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

t_complex	c_minus(t_complex x, t_complex y)
{
	t_complex res;

	res.r = x.r - y.r;
	res.i = x.i - y.i;
	return (res);
}

t_complex	c_minus_double(t_complex x, double y)
{
	t_complex res;

	res.r = x.r - y;
	res.i = x.i;
	return (res);
}
