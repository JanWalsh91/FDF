/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_abs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:56:06 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/01 11:27:03 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Gets the absolute value of complex number x and returns the result.
*/

t_complex	c_abs(t_complex x)
{
	x.r < 0 ? x.r *= -1 : 0;
	x.i < 0 ? x.i *= -1 : 0;
	return (x);
}
