/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpts_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:32:13 by jwalsh            #+#    #+#             */
/*   Updated: 2017/06/27 13:29:23 by jwalsh           ###   ########.fr       */
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
			d->mpts_3d[i.y][i.x] = m_v_mult(d->pts_3d[i.y][i.x],
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
	t_matrix	new;

	new = m_new_identity();
	new = m_mult(d->z_matrix, d->matrix);
	i.y = 0;
	while (i.y < d->ref.y)
	{
		i.x = 0;
		while (i.x < d->ref.x)
		{
			d->mpts_3d[i.y][i.x] = m_v_mult(d->pts_3d[i.y][i.x],
			new);
			++i.x;
		}
		++i.y;
	}
}
