/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:02:42 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/09 12:42:09 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	c;
	char	*str;

	c = 0;
	str = NULL;
	str = (ft_strnew(50));
	str = (strcpy(str, "12345"));
	while (c < 127)
	{
		str[0] = c;
		printf("c : %i\n", c);
		printf("   atoi: %i\n", atoi(str));
		printf("ft_atoi: %i\n", ft_atoi(str));
		c++;
	}
	return (0);
}
