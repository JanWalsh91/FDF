/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:28:25 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/06 17:51:34 by jwalsh           ###   ########.fr       */
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

#define MAX_WINDOW_WIDTH 2400
#define MAX_WINDOW_HEIGHT 1300
#define MAX_SEGMENT_LENGTH 10
#define FRAME_WIDTH 50 //?
#define USAGE "Usage : ./fdf <filename> [ case_size z_size ]"

typedef struct s_input
{
	
}

int		display_usage(void);
int		error(void);
int		ft_error(char *error_msg);
void	fdf(char *input);
int		check_file(char *input);
int		get_pts_num(char **s);


#endif
