/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:11:44 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/07 18:32:31 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	*src;
	char	*dst;
	char	*src2;
	char	*dst2;

	if (ac != 3)
	{
		printf("please enter a dst and a src\n");
		return (0);
	}
	dst = ft_memalloc(sizeof(av[1]));
	src = ft_memalloc(sizeof(av[2]));
	dst = memcpy(dst, av[1], ft_strlen(av[1]) + 1);
	src = memcpy(src, av[2], ft_strlen(av[2]) + 1);
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("strcat return: %s\nresults\n", strcat(dst, src));
	printf("src: %s\n", src);
	printf("dst: %s\n --- \n", dst);
	dst2 = ft_memalloc(sizeof(av[1]));
	src2 = ft_memalloc(sizeof(av[2]));
	dst2 = memcpy(src2, av[1], ft_strlen(av[1]) + 1);
	src2 = memcpy(dst2, av[2], ft_strlen(av[2]) + 1);
	printf("ft_strcat return: %s\nresults:\n", ft_strcat(dst2, src2));
	printf("src: %s\n", src2);
	printf("dst: %s\n", dst2);
	return (0);
}
