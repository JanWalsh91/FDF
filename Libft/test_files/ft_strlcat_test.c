/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:11:52 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/07 17:43:02 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*src;
	char	*dst;
	size_t	size;

	if (ac != 4)
	{
		printf("please enter a dst string, a src string and a number\n");
		return (0);
	}
	dst = av[1];
	src = av[2];
	size = atoi(av[3]);
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("size: %lu\n\n", size);
	printf("strlcat return: %lu\nresults\n", strlcat(dst, src, size));
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("size: %lu\n --- \n", size);
	src = av[1];
	dst = av[2];
	size = atoi(av[3]);
	printf("ft_strlcat return: %i\nresults:\n", ft_strlcat(dst, src, size));
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("size: %lu\n", size);
	return (0);
}
