/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:41:10 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/22 14:28:17 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** Displays a table of the height of the 3D coords.
*/

void	print_pts_3d(t_data data)
{
	int	y;
	int	x;

	y = 0;
	printf("print_pts_3d: (x, y, z)\n");
	while (y < data.ref.y)
	{
		x = 0;
		while (x < data.ref.x)
		{
			printf("(%.2f, %.2f, %.2f) ", data.pts_3d[y][x].x,
					data.pts_3d[y][x].y, data.pts_3d[y][x].z);
			++x;
		}
		printf("\n");
		y++;
	}
}

void	print_pts_2d(t_data d)
{
	int	y;
	int	x;

	y = 0;
	printf("print_pts_2d: (y, x)\n");
	while (y < d.ref.y)
	{
		x = 0;
		while (x < d.ref.x)
		{
			printf("(%.2f, %.2f) ", d.pts_2d[y][x].y, d.pts_2d[y][x].x);
			++x;
		}
		printf("\n");
		y++;
	}
}

void	print_colors(t_data d)
{
	int	y;
	int	x;

	y = 0;
	printf("print_colors: (y, x)\n");
	while (y < d.ref.y)
	{
		x = 0;
		while (x < d.ref.x)
		{
			printf("%i ", d.colors[0][y][x]);
			++x;
		}
		printf("\n");
		y++;
	}
}
