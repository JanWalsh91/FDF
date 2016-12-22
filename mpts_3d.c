/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpts_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:32:13 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/22 14:32:16 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int		init_set_mpts3d(t_data *d)
{
	t_pt2	i;

	if (!(d->mpts_3d = (t_vec3 **)malloc(sizeof(t_vec3 *) * d->ref.y)))
		return (return_error());
	i.y = 0;
	while (i.y < d->ref.y)
	{
		if (!(d->mpts_3d[i.y] = (t_vec3 *)malloc(sizeof(t_vec3) * d->ref.x)))
			return (return_error());
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
	t_pt2		i;
	t_matrix4	new;

	new = new_identity_matrix();
	new = matrix4_product(d->z_matrix, d->matrix);
	i.y = 0;
	while (i.y < d->ref.y)
	{
		i.x = 0;
		while (i.x < d->ref.x)
		{
			d->mpts_3d[i.y][i.x] = vec3_matrix4_product(d->pts_3d[i.y][i.x],
			new);
			++i.x;
		}
		++i.y;
	}
}
