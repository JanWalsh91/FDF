/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:36:26 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/26 16:47:31 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main (int ac, char **av)
{
	char	*src;
	char	*dst;
	size_t	len;

	if (ac != 4 && ac != 3)
	{
		printf("Please enter dst, src, len or dst, len for testing overlap\n");
		return (0);
	}
	if (ac == 4)
	{
		dst = ft_strdup(av[1]);
		src = ft_strdup(av[2]);
		len = ft_atoi(av[3]);
		printf("dst: %s\n", dst);
		printf("src: %s\n", src);
		printf("memmove result: %s\n", memmove(dst, src, len));
		printf("dst: %s\n", dst);
		printf("src: %s\n --- \n", src);
		dst = ft_strdup(av[1]);
		src = ft_strdup(av[2]);
		len = ft_atoi(av[3]);
		printf("dst: %s\n", dst);
		printf("src: %s\n", src);
		printf("ft_memmove result: %s\n", ft_memmove(dst, src, len));
		printf("dst: %s\n", dst);
		printf("src: %s\n", src);
		return(0);
	}
	if (ac == 3)
	{
		src = ft_memalloc(sizeof(av[1]));
		dst = ft_memalloc(sizeof(av[1]));
		dst = strcpy(dst, av[1]);
		src = strcpy(src, av[1]);
		len = ft_atoi(av[2]);
		printf("dst: %s\n", dst);
		printf("src: %s\n", src);
		printf("memmove result: %s\n", memmove(dst + 3, src, len));
		printf("dst: %s\n", dst);
		printf("src: %s\n --- \n", src);
		dst = strcpy(dst, av[1]);
		src = strcpy(src, av[1]);
		len = ft_atoi(av[2]);
		printf("dst: %s\n", dst);
		printf("src: %s\n", src);
		printf("ft_memmove result: %s\n", ft_memmove(dst + 3, src, len));
		printf("dst: %s\n", dst);
		printf("src: %s\n", src);
		return(0);
	}
}
