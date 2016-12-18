/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:48:27 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/18 16:25:18 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

#include <math.h>
#include <stdlib.h>

typedef struct	s_vec2
{
	float	x;
	float	y;
}				t_vec2;

typedef struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef float **t_matrix4;

/*
** Vector_fnct1
*/

float	vec_length(t_vec3 vec);
t_vec3	vec_normalize(t_vec3 vec);
float	vec_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec_cross_product(t_vec3 vec1, t_vec3 vec2);
double	to_radian(double a);


/*
** Vector_fnct2
*/

t_vec3	vec_plus(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec_minus(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec_product(t_vec3 vec1, float i);

/*
** Matrix_fnct1
*/

t_matrix4	new_matrix(void);
t_matrix4	new_identity_matrix(void);
t_matrix4	new_scaling_matrix(float i);
t_matrix4	matrix4_product(t_matrix4 m1, t_matrix4 m2);
t_vec3		vec3_matrix4_product(t_vec3 p, t_matrix4 m);

/*
** Matrix_fnct2
*/

t_matrix4	new_rotation_matrix(float angle, char axis);
t_matrix4	matrix4_translation(t_matrix4 m, t_vec3 v);

#endif
