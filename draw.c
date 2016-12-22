/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:06:12 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/22 15:08:11 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** Calls on draw_line between each relevant 2D point.
*/

void	draw_image(t_data *d, t_env *e)
{
	t_pt2	i;

	e->draw.image = mlx_get_data_addr(e->img.mlx, &(e->draw.bpp),
			&(e->draw.size_line), &(e->draw.endian));
	i.y = 0;
	while (i.y < d->ref.y)
	{
		i.x = 0;
		while (i.x < d->ref.x)
		{
			(i.x + 1 != d->ref.x) ? draw_line(e,
					d->pts_2d[i.y][i.x],
					d->pts_2d[i.y][i.x + 1],
					d->colors[d->c][i.y][i.x],
					d->colors[d->c][i.y][i.x + 1]) : 0;
			(i.y + 1 != d->ref.y) ? draw_line(e,
					d->pts_2d[i.y][i.x],
					d->pts_2d[i.y + 1][i.x],
					d->colors[d->c][i.y][i.x],
					d->colors[d->c][i.y + 1][i.x]) : 0;
			++i.x;
		}
		++i.y;
	}
}

/*
** Determines the pixels that need to be drawn between two 2D pts.
*/

void	draw_line(t_env *e, t_vec2 p1, t_vec2 p2, int c1, int c2)
{
	t_incr	incr;
	t_vec2	pt;
	float	color;
	int		v;

	incr = get_incr(p1, p2, c1, c2);
	v = 0;
	pt.x = p1.x;
	pt.y = p1.y;
	color = c1;
	while (v < incr.steps)
	{
		draw_pixel(e, ft_round(pt.x), ft_round(pt.y),
				color +
				ft_round(incr.r * v) * 0x10000 +
				ft_round(incr.g * v) * 0x100 +
				ft_round(incr.b * v));
		pt.x += incr.x;
		pt.y += incr.y;
		++v;
	}
}

/*
** Puts one pixel to the image at coordinate x, y.
*/

void	draw_pixel(t_env *e, int x, int y, int color)
{
	unsigned int	*tmp;

	tmp = (unsigned int *)(e->draw.image + y*e->draw.size_line +
			x * e->draw.bpp / 8);
	*tmp = color;
}
