/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:36:49 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/07 15:13:40 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*s1;
	char	*s2;
	int		i;

	if (ac != 4)
	{
		printf("Please enter s1, s2, size\n");
		return (0);
	}
	s1 = av[1];
	s2 = av[2];
	i = ft_atoi(av[3]);
	printf("s1: %s\ns2: %s\ni: %d\n", s1, s2, i);
	printf("strncmp: %d\n", strncmp(s1, s2, i));
	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, i));
}
