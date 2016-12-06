/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:06:02 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/09 17:03:14 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Please enter a parameter\n");
		return (0);
	}
	printf("ft_itoa result: %s\n", ft_itoa(ft_atoi((const char*)av[1])));
}
