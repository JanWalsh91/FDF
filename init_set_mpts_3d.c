/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_set_mpts_3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:54:16 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/18 16:22:30 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_set_mpts3d(t_data *d)
{
	t_pt2	i;

	if (!(d->mpts_3d = (t_vec3 **)malloc(sizeof(t_vec3 *) * d->ref.y)))
		return (error());
	i.y = 0;
	while (i.y < d->ref.y)
	{
		if (!(d->mpts_3d[i.y] = (t_vec3 *)malloc(sizeof(t_vec3) * d->ref.x)))
			return (error());
		i.x = 0;
		while (i.x < d->ref.x)
		{
			d->mpts_3d[i.y][i.x] = vec3_matrix4_product(d->pts_3d[i.y][i.x],
			d->matrix);
			++i.x;
		}
		++i.y;
	}
	return (1);
}

void	update_mpts3d(t_data *d)
{
	t_pt2	i;

	i.y = 0;
	while (i.y < d->ref.y)
	{
		i.x = 0;
		while (i.x < d->ref.x)
		{
			d->mpts_3d[i.y][i.x] = vec3_matrix4_product(d->pts_3d[i.y][i.x],
			d->matrix);
			++i.x;
		}
		++i.y;
	}
}