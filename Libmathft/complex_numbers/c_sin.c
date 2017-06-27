/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:13:51 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 16:15:01 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Returns the sine of  complex number x.
*/

t_complex	c_sin(t_complex x)
{
	t_complex res;

	res.r = sin(x.r);
	res.i = sin(x.i);
	return (res);
}
