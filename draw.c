/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:06:12 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/27 14:27:35 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** Calls on draw_line between each relevant 2D point.
*/

void	draw_image(t_data *d, t_env *e)
{
	t_pt2	i;
	t_pt2	c;

	e->draw.image = mlx_get_data_addr(e->img.mlx, &(e->draw.bpp),
			&(e->draw.size_line), &(e->draw.endian));
	i.y = 0;
	i.x = 0;
	while (i.y < d->ref.y)
	{
		c.x = d->colors[d->c][i.y][i.x];
		if (i.x + 1 != d->ref.x)
		{
			c.y = d->colors[d->c][i.y][i.x + 1];
			draw_line(e, d->pts_2d[i.y][i.x], d->pts_2d[i.y][i.x + 1], c);
		}
		if (i.y + 1 != d->ref.y)
		{
			c.y = d->colors[d->c][i.y + 1][i.x];
			draw_line(e, d->pts_2d[i.y][i.x], d->pts_2d[i.y + 1][i.x], c);
		}
		increment_index(&i.x, &i.y, d);
	}
}

/*
** Determines the pixels that need to be drawn between two 2D pts.
*/

void	draw_line(t_env *e, t_vec2 p1, t_vec2 p2, t_pt2 c)
{
	t_incr	incr;
	t_vec2	pt;
	float	color;
	int		v;

	incr = get_incr(p1, p2, c.x, c.y);
	v = 0;
	pt.x = p1.x;
	pt.y = p1.y;
	color = c.x;
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

	tmp = (unsigned int *)(e->draw.image + y * e->draw.size_line +
			x * e->draw.bpp / 8);
	*tmp = color;
}
