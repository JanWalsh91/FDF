/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:47:19 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/03 16:55:25 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_strlen(const char*s);

int	main(void)
{
	char str[50];

	strcpy(str, "This is a test.");
	printf("%lu\n", (strlen(str)));
	printf("%d\n", (ft_strlen(str)));
	return (0);
}
