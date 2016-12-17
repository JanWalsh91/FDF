/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:28:25 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/17 12:57:04 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "minilibx_macos/mlx.h"
#include "Libft/libft.h"
#include "vec.h"
#include "colors.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

/*
** Recommended window max size: (2400, 1300)
*/

#define USAGE "Usage : ./fdf <filename> [ case_size z_size ]"
#define MAX_WIN_W 2400
#define MAX_WIN_H 1300
#define MAX_UNIT_SIZE 50
#define FRAME_WIDTH 1 // will be multiplied by unit_size
#define FLT_MIN 1.175494e-38
#define FLT_MAX 3.402823e+38

/*
typedef struct	s_colors
{
	int			**c; //values of color for each point
	s_colors	*next;
	s_colors	*previous;
}				t_colors;
*/

typedef struct	s_incr
{
	float	steps;
	float	x;
	float	y;
	float	r;
	float	g;
	float	b;
	//float	color;
}				t_incr;

typedef struct	s_image
{
	void	*mlx;
	int		h;
	int		w;

}				t_image;

typedef struct	s_window
{
	void	*mlx;
	int		h;
	int		w;
}				t_window;

typedef struct	s_draw_tools
{
	int		bpp;
	int		size_line;
	int		endian;
	unsigned int		*tmp;
	char	*image;
}				t_draw_tools;

typedef struct	s_env
{
	void			*mlx;
	t_window		win;
	t_image			img;
	t_draw_tools	draw;
}				t_env;

typedef struct	s_pt2
{
	int	x;
	int	y;
}				t_pt2;

typedef struct	s_d2
{
	t_vec2	min;
	t_vec2	max;
}				t_d2;

typedef struct	s_d3
{
	t_vec3	min;
	t_vec3	max;
}				t_d3;

typedef struct	s_data
{
	char		*s; //String we read and store file contents.
	t_pt2		ref; //number of rows and columns. Used to access points.
	t_vec3		**pts_3d; // 2D array of 3D coordinates
	t_vec2		**pts_2d; // 2D array of 2D coordinates
	//t_colors	**colors; //pointer to start of chained list with colors.;
	int			***colors; // 2D array of color values
	int			c; // index of the color set.
	t_d2		d2; // min and max of 2D point coordinates
	t_d3		d3; // min and max of 3D point coordinates
	int			unit_size;
	t_vec2		center; // 2D coords of vector to origin of canvas
	int			color_input; // 1 if input determines colors.
	
	t_vec3	unit; // used?

}				t_data;

/*
** Main
*/

void	fdf(char *input);
int		display_usage(void);

/*
** Data verification and preparation.
*/

int		error(void);
int		check_line(char *line, t_data *d);
int		set_data(t_data *data);
int		set_pt(t_data *datai, t_pt2 *i);
int		set_colors(t_data *data);
int		get_color(char **s);
int		get_hex(char *tmp, int length);
int		get_hex_value(char c);
void	increment_index(int *x, int *y, t_data *data);

/*
** Set and reset values
*/

void	set_default_values(t_data *data);
void	set_palettes(t_data *d);
void	reset_ref(t_pt2 *ref);
void	reset_d3(t_d3 *d3);
void	reset_d2(t_d2 *d2);
void	reset_center(t_vec2 *center);

/*
** Get
*/

void	get_d3(t_data *d);
void	get_d2(t_data *d);
void	update_2d_coords(t_data *data);
void	get_center(t_data *d);
t_incr	get_incr(t_vec2 p1, t_vec2 p2, int c1, int c2);
void	get_color_incr(t_incr *incr, int c1, int c2, float steps);

/*
** Flow control functions.
*/

int		init_window(t_data *data, t_env *e, char *input);
int		init_pts_2d(t_data *data);
void	get_2d_coords(t_data *data, t_vec2 *p, int x, int y);
void	get_init_win_size(t_env *e, t_data *d);
void	put_2d_to_scale(t_data *d);

/*
** Draw functions
*/

void	draw_image(t_data *data, t_env *e);
void	draw_line(t_env *e, t_vec2 p1, t_vec2 p2, int c1, int c2);
void	draw_pixel(t_env *e, int x, int y, int color);

/*
** Error handling
*/

int		ft_error(char *error_msg);
int		read_file(char *input, t_data *data);

/*
** Debugging ... ///REMOVE///
*/

void	print_pts_3d(t_data data);
void	print_pts_2d(t_data data);
void	print_colors(t_data data);

#endif
