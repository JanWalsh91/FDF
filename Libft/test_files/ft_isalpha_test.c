/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:43:41 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/04 14:22:29 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c);

int	main(void)
{
	char c;

	c = 'A';
	printf("letter: %c isalpha: %d\n", c, isalpha(c));
	printf("letter: %c ft_isalpha: %d\n", c, ft_isalpha(c));
	return (0);
}
