/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:28:25 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/22 15:12:39 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "minilibx_macos/mlx.h"
#include "Libft/libft.h"
#include "keycode_mac.h"
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
#define MIN_WIN_W 350
#define MIN_WIN_H 200
#define MAX_UNIT_SIZE 50
#define FRAME_WIDTH 2 //number of unit_size wide.
#define FLT_MIN 1.175494e-38
#define FLT_MAX 3.402823e+38

/*
** Colors for 4 sets.
*/

#define P0C0 DARK_GREEN
#define P0C1 GREEN
#define P0C2 SADDLEBROWN
#define P0C3 GAINSBORO

#define P1C0 STEEL_BLUE
#define P1C1 0xAAAAFF
#define P1C2 DEEP_PINK
#define P1C3 HOT_PINK

#define P2C0 MAROON
#define P2C1 INDIAN_RED
#define P2C2 SALMON
#define P2C3 GOLD

#define P3C0 GOLDEN_ROD
#define P3C1 LIGHT_SEA_GREEN
#define P3C2 TEAL
#define P3C3 HOT_PINK

/*
** Instructions
*/

#define HEADER "Click anywhere for instructions"
#define LINE1 "c: next color palette"
#define LINE2 "- / +: zoom"
#define LINE3 "[ / ]: modify height unit"
#define LINE4 "q / a: rotate around x axis"
#define LINE5 "w / s: rotate around y axis"
#define LINE6 "e / d: rotate around z axis"
#define LINE7 "arrow keys: move around"
#define LINE8 "Space: reset"

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

typedef struct	s_pt2
{
	int	x;
	int	y;
}				t_pt2;

typedef struct	s_incr
{
	float	steps;
	float	x;
	float	y;
	float	r;
	float	g;
	float	b;
}				t_incr;

typedef struct	s_image
{
	void	*mlx;
	int		h;
	int		w;
	t_pt2	pos;

}				t_image;

typedef struct	s_window
{
	void	*mlx;
	int		h;
	int		w;
}				t_window;

typedef struct	s_draw_tools
{
	int				bpp;
	int				size_line;
	int				endian;
	char			*image;
}				t_draw_tools;

typedef struct	s_env
{
	void			*mlx;
	t_window		win;
	t_image			img;
	t_draw_tools	draw;
}				t_env;

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
	t_matrix4	matrix;
	t_matrix4	z_matrix;
	t_vec3		**mpts_3d;
	t_vec2		**pts_2d; // 2D array of 2D coordinates
	int			***colors; // 2D arrays of color values for each point
	int			c; // index of the color set.
	t_d2		d2; // min and max of 2D point coordinates
	t_d3		d3; // min and max of 3D point coordinates
	int			unit_size; // width in pixels of a unit.
	int			zoom;
	//t_pt2		zoom_fix;
	t_vec2		center; // 2D coords of vector to origin of canvas
	int			color_input; // 1 if input determines colors.
}				t_data;

typedef struct s_all
{
	t_data	d;
	t_env	e;
}				t_all;

/*
** Main
*/

void	fdf(char *input);
int		display_usage(void);
int		error(void);

/*
** Data verification and preparation.
*/

int		read_file(char *input, t_data *data);
int		init_colors(t_data *data);
int		init_set_data(t_data *data);
int		init_set_2d_pts(t_data *d);
int		set_color(char **s);
void	increment_index(int *x, int *y, t_data *data);

/*
** Set and reset values
*/

void	set_default_values(t_data *d, t_env *e);
int		init_set_mpts3d(t_data *d);
int		init_set_palettes(t_data *d);
void	reset_d3(t_d3 *d3);
void	reset_d2(t_d2 *d2);
void	reset_center(t_vec2 *center);
void	reset_img_pos(t_pt2 *pos);

/*
** Get
*/

void	get_d3(t_data *d);
void	get_d2(t_data *d);
void	update_2d_coords(t_data *data);
void	update_mpts3d(t_data *d);
void	get_center(t_data *d);
t_incr	get_incr(t_vec2 p1, t_vec2 p2, int c1, int c2);
void	get_color_incr(t_incr *incr, int c1, int c2, float steps);
void	get_unit_size(t_data *d);

/*
** Flow control functions.
*/

void	init_window(t_data *d, t_env *e, char *input);
int		init_get_pts_2d(t_data *data);
void	get_win_size(t_env *e, t_data *d);
void	get_img_size(t_env *e, t_data *d);
void	update_instructions(t_env *e, int a);
void	update_image(t_data *d, t_env *e);
void	update_img_pos_y(int i, t_env *e);
void	update_img_pos_x(int i, t_env *e);
void	update_img_pos_reset(t_env *e);
void	update_unit_size(int i, t_env *e, t_data *d);
void	update_z_coord(int i, t_env *e, t_data *d);
void	update_colors(t_data *d, t_env *e);
void	rotate(char c, int i, t_env *e, t_data *d);
void	recenter(t_env *v, t_data *d);


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

/*
** Debugging ... ///REMOVE///
*/

void	print_pts_3d(t_data data);
void	print_pts_2d(t_data data);
void	print_colors(t_data data);

#endif
