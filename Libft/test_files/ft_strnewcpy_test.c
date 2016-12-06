/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewcpy_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:18:14 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/08 12:33:29 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*dst;

	if (ac != 2)
	{
		printf("Please enter one string to cpy\n");
		return (0);
	}
	dst = NULL;
	ft_strnewcpy(&dst, av[1]);
	printf("result of cpy: %s\n", dst);
	dst[1] = 'O';
	av[1][1] = 'R';
	printf("Post-modification:\ndst: %s\nav[1]: %s\n", dst, av[1]);
	return (0);
}
