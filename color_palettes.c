/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palettes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:19:26 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/24 16:40:49 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void static	set_palette(t_data *d, int i, int *p);
void static	set_palette_arrays(int ***p);

/*
** Allocates memory to 4 or 5 2D lists for the colors of each point.
** Sets the colors of the last 4 2D lists based on predefined color values.
*/

int		init_colors(t_data *d)
{
	int		i;
	t_pt2	 p;

	if (!(d->colors = (int ***)malloc(sizeof(int **) * (4 + d->color_input))))
		return (return_error());
	i = 0;
	while (i < 4 + d->color_input)
	{
		if (!(d->colors[i] = (int **)malloc(sizeof(int *) * d->ref.y)))
			return (return_error());
		p.y = 0;
		while (p.y < d->ref.y)
		{
			if (!(d->colors[i][p.y] = (int *)malloc(sizeof(int) * d->ref.x)))
				return (return_error());
			p.x = 0;
			while (p.x < d->ref.x)
				d->colors[i][p.y][p.x++] = DARK_GRAY;
			++p.y;
		}
		++i;
	}
	return (1);
}

/*
** Sets up the other color palettes as defined in the header.
*/

int		init_set_palettes(t_data *d)
{
	int	**palettes;
	int	y;
	int i;

	y = -1;
	if (!(palettes = (int **)malloc(sizeof(int *) * 4)))
		return (return_error());
	while (++y < 4)
		if (!(palettes[y] = (int *)malloc(sizeof(int) * 4)))
			return (return_error());
	set_palette_arrays(&palettes);
	i = d->color_input;
	set_palette(d, i, palettes[0]);
	set_palette(d, ++i, palettes[1]);
	set_palette(d, ++i, palettes[2]);
	set_palette(d, ++i, palettes[3]);
	y = -1;
	while (++y < 4)
		free(palettes[y]);
	free(palettes);
	return (1);
}

void static set_palette(t_data *d, int num, int *p)
{
	float	height;
	t_pt2	i;

	i.y = 0;
	get_d3(d);
	height = d->d3.max.z - d->d3.min.z;
	while (i.y < d->ref.y)
	{
		i.x = 0;
		while (i.x < d->ref.x)
		{
			if (d->pts_3d[i.y][i.x].z < (height / 4))
				d->colors[num][i.y][i.x] = p[0];
			else if (d->pts_3d[i.y][i.x].z <= (2 * height / 4))
				d->colors[num][i.y][i.x] = p[1];
			else if (d->pts_3d[i.y][i.x].z <= (3 * height / 4))
				d->colors[num][i.y][i.x] = p[2];
			else if (d->pts_3d[i.y][i.x].z <= (height))
				d->colors[num][i.y][i.x] = p[3];
			//(d->pts_3d[i.y][i.x].z < 0) ? d->colors[num][i.y][i.x] = 0x0505AA : 0;
			++i.x;
		}
		++i.y;
	}
}

void	 static	set_palette_arrays(int ***p)
{
	(*p)[0][0] = P0C0;
	(*p)[0][1] = P0C1;
	(*p)[0][2] = P0C2;
	(*p)[0][3] = P0C3;
	(*p)[1][0] = P1C0;
	(*p)[1][1] = P1C1;
	(*p)[1][2] = P1C2;
	(*p)[1][3] = P1C3;
	(*p)[2][0] = P1C0;
	(*p)[2][1] = P2C1;
	(*p)[2][2] = P2C2;
	(*p)[2][3] = P2C3;
	(*p)[3][0] = P3C0;
	(*p)[3][1] = P3C1;
	(*p)[3][2] = P3C2;
	(*p)[3][3] = P3C3;
}
