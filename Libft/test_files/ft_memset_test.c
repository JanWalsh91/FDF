/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:30:19 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/06 14:44:02 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len);

int	main(void)
{
	char	str[15];

	strcpy(str, "This is a test.");
	puts(str);
	memset(str, '$', 20);
	puts(str);
	ft_memset(str, 'o', 10);
	puts(str);
	return (0);
}
