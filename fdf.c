/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:08:38 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/18 16:00:41 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Controls the MLX flow by reacting to user input after read the file and
** setting the data.
*/

void	fdf(char *input)
{
	t_data	data;
	t_env	e;

	set_default_values(&data);
	if (!read_file(input, &data))
		return ;
	if (!(init_set_data(&data)))
			return ;
	e.mlx = mlx_init();
	init_window(&data, &e, input);
	mlx_loop(e.mlx);
}
