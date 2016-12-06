/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:20:46 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/11 13:20:45 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	get_word_count(char *s, char c);

int		main(int ac, char **av)
{
	size_t	i;
	char	**r;

	if (ac != 2)
	{
		printf("Please enter 1 parameter\n");
		return (0);
	}
	//printf("get_word_count result: %lu\n", get_word_count(av[1], ' '));
	i = 0;
	r = ft_strsplit(av[1], ' ');
	while (r && r[i])
	{
		printf("final result[%lu]: %s\n", i, r[i]);
		i++;
	}
	return (0);
}

/*
** lskdhjf
** 
*/
