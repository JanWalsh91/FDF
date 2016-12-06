/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:42:05 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/06 14:37:07 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c);

int	main(void)
{
	char	chars[9];
	int		i;

	chars[0] = 'a';
	chars[1] = 'R';
	chars[2] = 'l';
	chars[3] = 40;
	chars[4] = 11;
	chars[5] = 9;
	chars[6] = 127;
	chars[7] = 7;
	chars[8] = 0;
	i = 0;
	while (chars[i])
	{
		printf("letter: %c\n", chars[i]);
		printf("isprint: %d\n", isprint(chars[i]));
		printf("ft_isprint:%d\n", ft_isprint(chars[i]));
		i++;
	}
	return (0);
}
