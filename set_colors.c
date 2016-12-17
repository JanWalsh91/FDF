/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:28:08 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/17 13:24:43 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void static	set_palette(t_data *d, int i, int *p);
void static	set_palette_arrays(int ***p);

/*
** Allocates memory to 4 or 5 2D lists for the colors of each point.
** Sets the colors of the last 4 2D lists based on predefined color values.
*/

int		set_colors(t_data *d)
{
	printf("set_colors\n");
	int		i;
	t_pt2	 p;

	if (!(d->colors = (int ***)malloc(sizeof(int **) * (4 + d->color_input))))
		return (0);
	i = 0;
	while (i < 4 + d->color_input)
	{
		if (!(d->colors[i] = (int **)malloc(sizeof(int *) * d->ref.y)))
			return (0);
		p.y = 0;
		while (p.y < d->ref.y)
		{
			if (!(d->colors[i][p.y] = (int *)malloc(sizeof(int) * d->ref.x)))
				return (0);
			p.x = 0;
			while (p.x < d->ref.x)
				d->colors[i][p.y][p.x++] = 0;
			++p.y;
		}
		++i;
	}
	//set_palettes(d);
	return (1);
}

void	set_palettes(t_data *d)
{
	printf("set_palettes\n");
	int	**palettes;
	int	y;
	int i;

	y = 0;
	if (!(palettes = (int **)malloc(sizeof(int *) * 4)))
		return ;
	while (y < 4)
	{
		if (!(palettes[y] = (int *)malloc(sizeof(int) * 4)))
			return ;
		++y;
	}
	set_palette_arrays(&palettes);
	printf("color input: %i\n", d->color_input);
	i = d->color_input;
	set_palette(d, i, palettes[0]);
	set_palette(d, ++i, palettes[1]);
	set_palette(d, ++i, palettes[2]);
	set_palette(d, ++i, palettes[3]);
}

void static set_palette(t_data *d, int num, int *p)
{
	printf("set_palette with num: %i\n", num);
	float	height;
	t_pt2	i;

	i.y = 0;
	height = d->d3.max.z - d->d3.min.z;
	printf("height: %f\n", height);
	while (i.y < d->ref.y)
	{
		printf("check1\n");
		i.x = 0;
		while (i.x < d->ref.x)
		{
			printf("-");
			printf("check at (y, x)(%i, %i): %.2f  ", i.y, i.x, d->pts_3d[i.y][i.x].z);
			printf("-");
			if (d->pts_3d[i.y][i.x].z < (height / 4))
			{
				d->colors[num][i.y][i.x] = p[0];
				printf("check\n");
			}
			else if (d->pts_3d[i.y][i.x].z <= (2 * height / 4))
				d->colors[num][i.y][i.x] = p[1];
			else if (d->pts_3d[i.y][i.x].z <= (3 * height / 4))
				d->colors[num][i.y][i.x] = p[2];
			else if (d->pts_3d[i.y][i.x].z <= (height))
				d->colors[num][i.y][i.x] = p[3];
			printf("added color: %i\n", d->colors[num][i.y][i.x]);
			++i.x;
		}
		++i.y;
	}
}

void	 static	set_palette_arrays(int ***p)
{
	(*p)[0][0] = DARK_MAGENTA;
	(*p)[0][1] = SEA_GREEN + 0x50;
	(*p)[0][2] = MAROON;
	(*p)[0][3] = WHITE;
	(*p)[1][0] = LAVENDER;
	(*p)[1][1] = HONEYDEW;
	(*p)[1][2] = AZURE;
	(*p)[1][3] = MISTY_ROSE;
	(*p)[2][0] = MAROON;
	(*p)[2][1] = INDIAN_RED;
	(*p)[2][2] = SALMON;
	(*p)[2][3] = GOLD;
	(*p)[3][0] = BLUE;
	(*p)[3][1] = LIME;
	(*p)[3][2] = TEAL;
	(*p)[3][3] = CYAN;
}
