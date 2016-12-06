/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:14:00 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/08 16:06:46 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*src;
	char	*dst;

	if (ac != 3)
	{
		printf("Please input src and dst\n");
		return (0);
	}
	ft_strnewcpy(&src, av[2]);
	ft_strnewcpy(&dst, av[1]);
	printf("src: %s\ndst: %s\n", src, dst);
	printf("strcpy result: %s\n -- \n", strcpy(dst, src));
	ft_strnewcpy(&src, av[2]);
	ft_strnewcpy(&dst, av[1]);
	printf("src: %s\ndst: %s\n", src, dst);
	printf("ft_strcpy result: %s\n", ft_strcpy(dst, src));
	

	return (0);
}
