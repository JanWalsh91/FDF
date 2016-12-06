/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:07:09 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/08 17:48:34 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)	
{
	char	*src;
	char	*dst;
	char	*src2;
	char	*dst2;
	char	*test;

	test = NULL;
	if (ac != 4)
	{
		printf("Please input src, dst and len\n");
		return (0);
	}
	ft_strnewcpy(&src, av[2]);
	ft_strnewcpy(&dst, av[1]);
	printf("src: %s\ndst: %s\n", src, dst);
	printf("strncpy result: %s\n -- \n", strncpy(dst, src, atoi(av[3])));
	ft_strnewcpy(&src2, av[2]);
	ft_strnewcpy(&dst2, av[1]);
	printf("src: %s\ndst: %s\n", src2, dst2);
	printf("ft_strncpy result: %s\n", ft_strncpy(dst2, src2, atoi(av[3])));


	return (0);
}
