/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:58:52 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/21 15:34:32 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the absolute value of int n.
*/

#include "libmathft.h"

unsigned long	ft_abs(long n)
{
	unsigned long	result;

	result = (n < 0) ? -n : n;
	return (result);
}
