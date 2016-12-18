/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:23:51 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/18 16:33:21 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Sets default values for many variables. Called on once at the beginning of
** the program.
*/

void	set_default_values(t_data *d)
{
	printf("set_default_values\n");
	d->color_input = 0;
	d->c = 0;
	d->s = NULL;
	d->unit_size = 1;
	d->matrix = new_identity_matrix();
	reset_ref(&(d->ref));
	reset_d3(&(d->d3));
	reset_d2(&(d->d2));
	reset_center(&(d->center));
}

/*
** Only needs to be called on at the beginning.
*/

void	reset_ref(t_pt2 *ref)
{
	ref->x = 0;
	ref->y = 0;
}

/*
** Resets min max values of the 3D coords.
** Called on when you need to reevaluate 
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

void	reset_d2(t_d2 *d2)
{
	d2->max.x = -FLT_MAX;
	d2->max.y = -FLT_MAX;
	d2->min.x = FLT_MAX;
	d2->min.y = FLT_MAX;
}

void	reset_center(t_vec2 *center) //should actually calculate the new center.
{
	center->x = 0;
	center->y = 0;
}
