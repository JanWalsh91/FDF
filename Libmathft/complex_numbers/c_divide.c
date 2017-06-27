/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_divide.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 11:59:32 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/29 11:59:34 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

t_complex	c_divide(t_complex x, t_complex y)
{
	t_complex res;

	res.r = (x.r * y.r + x.i * y.i) / (y.r * y.r + y.i * y.i);
	res.i = (x.i * y.r - x.r * y.i) / (y.r * y.r + y.i * y.i);
	return (res);
}
