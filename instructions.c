/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:49:26 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/27 12:59:24 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	display_header(t_env *e);
static void	display_instructions(t_env *e, int i);

/*
** Displays either the header or the instructions based on input.
*/

void		update_instructions(t_env *e, int a, int file_count)
{
	static int	i = 1;

	file_count = (file_count > 1) ? 2 : 1;
	if (a)
		i = (i) ? 0 : 1;
	!i ? display_instructions(e, file_count - 1) : display_header(e);
}

static void	display_header(t_env *e)
{
	mlx_string_put(e->mlx, e->win.mlx, 10, 15, GAINSBORO, HEADER);
}

static void	display_instructions(t_env *e, int i)
{
	mlx_string_put(e->mlx, e->win.mlx, 10, 15, 0x30FFFFFF, LINE1);
	mlx_string_put(e->mlx, e->win.mlx, 10, 30, 0x30FFFFFF, LINE2);
	mlx_string_put(e->mlx, e->win.mlx, 10, 45, 0x30FFFFFF, LINE3);
	mlx_string_put(e->mlx, e->win.mlx, 10, 60, 0x30FFFFFF, LINE4);
	mlx_string_put(e->mlx, e->win.mlx, 10, 75, 0x30FFFFFF, LINE5);
	mlx_string_put(e->mlx, e->win.mlx, 10, 90, 0x30FFFFFF, LINE6);
	mlx_string_put(e->mlx, e->win.mlx, 10, 105, 0x30FFFFFF, LINE7);
	mlx_string_put(e->mlx, e->win.mlx, 10, 120, 0x30FFFFFF, LINE8);
	if (i)
	{
		mlx_string_put(e->mlx, e->win.mlx, 10, 135, 0x30FFFFFF, LINE9);
		mlx_string_put(e->mlx, e->win.mlx, 10, 150, 0x30FFFFFF, LINE10);
	}
	mlx_string_put(e->mlx, e->win.mlx, 10, 135 + i * 30, 0x30FFFFFF, LINE11);
}
