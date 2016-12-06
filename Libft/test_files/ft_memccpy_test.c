/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:53:31 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/08 13:52:20 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	*src;
	char	*dst;
	size_t	size;
	char	*src2;
	char	*dst2;

	if (ac != 5)
	{
		printf("please enter a dst, a src, a char, and size\n");
		return (0);
	}
	ft_strnewcpy(&dst, av[1]);
	ft_strnewcpy(&src, av[2]);
	size = atoi(av[4]);
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("size: %lu\n\n", size);
	printf("memccpy return: %s\nresults\n", memccpy(dst, src, av[3][0], size));
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("size: %lu\n --- \n", size);
	ft_strnewcpy(&src2, av[1]);
	ft_strnewcpy(&dst2, av[2]);
	size = atoi(av[4]);
	printf("ft_memcpy return: %s\nresults:\n", ft_memccpy(dst, src, av[3][0], size));
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("size: %lu\n", size);
	return (0);
}
