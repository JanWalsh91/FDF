/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:35:30 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/08 13:20:58 by jwalsh           ###   ########.fr       */
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

	if (ac != 4)
	{
		printf("please enter a dst, a src and size\n");
		return (0);
	}
	ft_strnewcpy(&dst, av[1]);
	ft_strnewcpy(&src, av[2]); 
	size = atoi(av[3]);
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("size: %lu\n\n", size);
	printf("memcpy return   : %s\nresults:\n", memcpy(dst, src, size));
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("size: %lu\n --- \n", size);
	ft_strnewcpy(&dst2, av[1]);
	ft_strnewcpy(&src2, av[2]); 
	size = atoi(av[3]);
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("size: %lu\n\n", size);
	printf("ft_memcpy return: %s\nresults:\n", (char *)ft_memcpy(dst, src, size));
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("size: %lu\n", size);
	return (0);
}
