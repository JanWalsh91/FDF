/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:22:59 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/04 14:24:55 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c);

int	main(void)
{
	char c;

	c = 'A';
	printf("char: %c isdigit: %d\n", c, isdigit(c));
	printf("char: %c ft_isdigit: %d\n", c, ft_isdigit(c));
	return (0);
}
