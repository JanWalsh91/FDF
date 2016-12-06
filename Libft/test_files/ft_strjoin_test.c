/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:31:24 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/05 16:36:35 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("Please enter two strings\n");
		return (0);
	}
	printf("ft_strjoin result: %s\n", ft_strjoin(av[1], av[2]));
	return (0);
}
