/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:04:54 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/22 16:50:21 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		return (display_usage());
	while (++i < ac)
		fdf(av[i]);
	return (0);
}

int	display_usage(void)
{
	ft_putendl(USAGE);
	return (0);
}

int	return_error(void)
{
	ft_putendl_fd(strerror(errno), 2);
	return (0);
}
