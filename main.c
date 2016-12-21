/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:04:54 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/17 17:10:13 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (display_usage());
	else
	{
		fdf(av[1]);
	}
	return (0);
}

int	display_usage(void)
{
	ft_putendl(USAGE);
	return (0);
}

int	error(void)
{
	ft_putendl_fd(strerror(errno), 2);
	return (0);
}
