/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:09:15 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/01 11:31:56 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** UNTESTED
*/

#include "libft.h"

char	*ft_to_base(int n, int b)
{
	int		t;
	char	*result;

	result = ft_strnew(1);
	if (b < 2)
		return (0);
	t = n;
	while (t != 0)
	{
		result = ft_straddcharfree(result, ((n % b) + '0'));
		n = n / b;
	}
	return(ft_strrev(result));
}
