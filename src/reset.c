/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:23:51 by jwalsh            #+#    #+#             */
/*   Updated: 2017/06/27 13:27:39 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** Sets default values for many variables. Called on once at the beginning of
** the program.
*/

void	set_default_values(t_all *a, int f_c, char **f_n, int i)
{
	a->d.file_count = f_c;
	a->d.file_names = f_n;
	a->d.file_index = i;
	a->d.color_input = 0;
	a->d.c = 0;
	a->d.s = NULL;
	a->d.unit_size = 1;
	a->d.zoom = 0;
	a->d.ref.x = 0;
	a->d.ref.y = 0;
	a->d.matrix = m_new_identity();
	a->d.z_matrix = m_new_identity();
	reset_d3(&(a->d.d3));
	reset_d2(&(a->d.d2));
	reset_img_pos(&(a->e.img.pos));
	reset_center(&(a->d.center));
}

/*
** Resets min max values of the 3D coords.
*/

void	reset_d3(t_d3 *d3)
{
	d3->max.x = -FLT_MAX;
	d3->max.y = -FLT_MAX;
	d3->max.z = -FLT_MAX;
	d3->min.x = FLT_MAX;
	d3->min.y = FLT_MAX;
	d3->min.z = FLT_MAX;
}

/*
** Resets min max values of the 2D coords.
*/

void	reset_d2(t_d2 *d2)
{
	d2->max.x = -FLT_MAX;
	d2->max.y = -FLT_MAX;
	d2->min.x = FLT_MAX;
	d2->min.y = FLT_MAX;
}

/*
** Resets the center.
*/

void	reset_center(t_vec2 *center)
{
	center->x = 0;
	center->y = 0;
}

/*
** Resets the position of the image.
*/

void	reset_img_pos(t_pt2 *pos)
{
	pos->x = 0;
	pos->y = 0;
}
