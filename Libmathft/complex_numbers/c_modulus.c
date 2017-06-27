/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_modulus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:30:29 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/21 15:31:01 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Calculates and returns the modulus of the complex number x.
*/

double	c_modulus(t_complex x)
{
	return (sqrt(pow(x.r, 2) + pow(x.i, 2)));
}
