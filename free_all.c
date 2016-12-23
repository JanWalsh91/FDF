/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 13:05:26 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/23 15:26:30 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	free_vec2_list(t_vec2 ***v, t_pt2 ref);
static void	free_vec3_list(t_vec3 ***v, t_pt2 ref);
static void	free_colors(int ****c, t_pt2 ref, int color_input);

void		free_all(t_all *a)
{
	if (!a)
		return ;
	free(a->d.to_free);
	free_matrix(&a->d.matrix);
	free_matrix(&a->d.z_matrix);
	free_vec2_list(&a->d.pts_2d, a->d.ref);
	free_vec3_list(&a->d.pts_3d, a->d.ref);
	free_vec3_list(&a->d.mpts_3d, a->d.ref);
	free_colors(&a->d.colors, a->d.ref, a->d.color_input);
}

void		free_matrix(t_matrix4 *m)
{
	int	y;

	y = -1;
	while (++y < 4)
		free((*m)[y]);
	free(*m);
	*m = NULL;
}


static void	free_vec2_list(t_vec2 ***v, t_pt2 ref)
{
	int	y;

	y = -1;
	while (++y < ref.y)
		free((*v)[y]);
	free(*v);
	*v = NULL;
}


static void	free_vec3_list(t_vec3 ***v, t_pt2 ref)
{
	int	y;

	y = -1;
	while (++y < ref.y)
		free((*v)[y]);
	free(*v);
	*v = NULL;
}

static void	free_colors(int ****c, t_pt2 ref, int color_input)
{
	int	y;
	int	i;

	i = -1;
	while (++i < 4 + color_input)
	{
		y = -1;
		while (++y < ref.y)
			free((*c)[i][y]);
		free((*c)[i]);
	}
	free(*c);
	*c = NULL;
}
