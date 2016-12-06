/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:41:18 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/08 18:01:15 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*big;
	char	*small;
	char	*big2;
	char	*small2;
	char	*test;

	test = NULL;
	if (ac != 3)
	{
		printf("Please input string and substring to find\n");
		return (0);
	}
	ft_strnewcpy(&big, av[1]);
	ft_strnewcpy(&small, av[2]);
	printf("big: %s\nsmall: %s\n", big, small);
	printf("strstr result: %s\n -- \n", strstr(big, small));
	ft_strnewcpy(&big2, av[1]);
	ft_strnewcpy(&small2, av[2]);
	printf("big: %s\nsmall: %s\n", big2, small2);
	printf("ft_strstr result: %s\n", ft_strstr(big2, small2));
	return (0);
}
