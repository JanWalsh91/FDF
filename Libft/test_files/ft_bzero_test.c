/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:19:14 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/06 14:33:45 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n);

int		main(void)
{
	char	str[50];

	strcpy(str, "this is a test.");
	bzero(str, 5);
	puts(str + 5);
	ft_bzero(str, 4);
	puts(str + 9);
	return (0);
}
