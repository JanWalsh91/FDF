/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:27:16 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/21 15:27:45 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Adds complex numbers x and y and returns the result.
*/

t_complex	c_add(t_complex x, t_complex y)
{
	t_complex res;

	res.r = x.r + y.r;
	res.i = x.i + y.i;
	return (res);
}
