/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:49:26 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/21 17:16:21 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	display_header(t_env *e);
static void	display_instructions(t_env *e);

void	update_instructions(t_env *e, int a)
{
	static int	i = 0;

	if (a)
		i = (i) ? 0 : 1;
	!i ? display_instructions(e) : display_header(e);
}

static void	display_header(t_env *e)
{
	mlx_string_put(e->mlx, e->win.mlx, 10, 15, GAINSBORO, HEADER);
}

static void	display_instructions(t_env *e)
{
	mlx_string_put(e->mlx, e->win.mlx, 10, 15, 0x30FFFFFF, LINE1);
	mlx_string_put(e->mlx, e->win.mlx, 10, 30, 0x30FFFFFF, LINE2);
	mlx_string_put(e->mlx, e->win.mlx, 10, 45, 0x30FFFFFF, LINE3);
	mlx_string_put(e->mlx, e->win.mlx, 10, 60, 0x30FFFFFF, LINE4);
	mlx_string_put(e->mlx, e->win.mlx, 10, 75, 0x30FFFFFF, LINE5);
	mlx_string_put(e->mlx, e->win.mlx, 10, 90, 0x30FFFFFF, LINE6);
	mlx_string_put(e->mlx, e->win.mlx, 10, 105, 0x30FFFFFF, LINE7);
	mlx_string_put(e->mlx, e->win.mlx, 10, 120, 0x30FFFFFF, LINE8);
}
