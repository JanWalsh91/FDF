/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:28:25 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/08 17:38:42 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "minilibx_macos/mlx.h"
#include "Libft/libft.h"
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
#define MAX_WINDOW_WIDTH 2400
#define MAX_WINDOW_HEIGHT 1300
#define MAX_SEGMENT_LENGTH 10
#define FRAME_WIDTH 50 //?

static int	g_user_set_colors = 0;

typedef struct	s_max
{
	int	x;
	int	y;
	int z;
}				t_max;

typedef struct	s_pt
{
	int	z;
	int	color;
}				t_pt;

int		display_usage(void);
int		error(void);
int		ft_error(char *error_msg);
void	fdf(char *input);
int		read_file(char *input, char **s, t_max *max);
void	set_t_max(t_max *max);
int		update_max_pts(char *line, t_max *max);
int		set_data(t_pt ****pts, char *s, t_max max);
int		update_pts(t_pt ****pts, char *line, t_max max);
int		set_pt(t_pt **pt, char **s);
int		get_color(char **s);
int		get_hex(char *tmp);
int		get_value(char c);


#endif
