/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmathft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 15:36:18 by jwalsh            #+#    #+#             */
/*   Updated: 2017/06/27 13:37:06 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATHFT_H
# define LIBMATHFT_H

# include <math.h>
# include <stdlib.h>

typedef struct	s_pt2
{
	int			x;
	int			y;
}				t_pt2;

typedef struct	s_dpt2
{
	double		x;
	double		y;
}				t_dpt2;

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef double	**t_matrix;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

unsigned long	ft_abs(long n);
long			ft_power(int n, int p);
double			to_radian(double a);
int				ft_round(float i);
int				ft_rgb_mix(int *colors, int n);

/*
** 3 x 3 Vector functions
*/

t_vec3			v_add(t_vec3 vec1, t_vec3 vec2);
t_vec3			v_cross(t_vec3 vec1, t_vec3 vec2);
double			v_dot(t_vec3 vec1, t_vec3 vec2);
int				v_isnan(t_vec3 v);
double			v_length(t_vec3 vec);
t_vec3			v_clamp(t_vec3 v, double min, double max);
t_vec3			v_mult(t_vec3 vec, t_vec3 i);
t_vec3			v_new(double x, double y, double z);
t_vec3			v_norm(t_vec3 vec);
t_vec3			v_scale(t_vec3 vec1, double i);
t_vec3			v_sub(t_vec3 vec1, t_vec3 vec2);

/*
** 4 x 4 Matrix functions
*/

t_matrix		m_add(t_matrix m1, t_matrix m2);
t_matrix		m_inverse(t_matrix m);
t_matrix		m_mult(t_matrix m1, t_matrix m2);
t_matrix		m_new_identity(void);
t_matrix		m_new_rodriguez(t_vec3 a, t_vec3 b);
t_matrix		m_new_rotate(float angle, char axis);
t_matrix		m_new_scale(double i);
t_matrix		m_new(void);
t_vec3			m_p_mult(t_vec3 p, t_matrix m);
t_matrix		m_scale(t_matrix m, double i);
t_matrix		m_translate(t_matrix m, t_vec3 v);
t_vec3			m_v_mult(t_vec3 v, t_matrix m);

/*
** Complex number functions
*/

t_complex		c_add(t_complex x, t_complex y);
t_complex		c_abs(t_complex x);
t_complex		c_add_float(t_complex x, double y, double z);
t_complex		c_divide(t_complex x, t_complex y);
t_complex		c_product(t_complex x, t_complex y);
t_complex		c_product_double(t_complex x, double y);
double			c_modulus(t_complex x);
t_complex		c_minus(t_complex x, t_complex y);
t_complex		c_minus_double(t_complex x, double y);
t_complex		c_sin(t_complex x);
t_complex		c_sphere(t_complex x);
t_complex		c_horseshoe(t_complex x);
t_complex		c_swirl(t_complex x);
t_complex		c_polar(t_complex x);

#endif
