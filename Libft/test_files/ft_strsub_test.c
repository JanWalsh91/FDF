/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:43:03 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/10 11:53:02 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len);

int		main(void)
{
	char	s1[50];
	char	s2[50];

	strcpy(s1, "");
	strcpy(s2, "123456789");
	printf("ft_strsub: %s\n", ft_strsub(s1, 2, 4));
	printf("ft_strsub: %s\n", ft_strsub(s2, 2, 4));
	return (0);
}
