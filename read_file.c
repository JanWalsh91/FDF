/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:01:12 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/08 17:44:36 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Reads the input with get_next_line and checks validity of lines and points
** while updating the array of point structures.
*/

int	read_file(char *input, char **s, t_max *max)
{
	int		fd;
	char	*line;
	int		ret;

	printf("read_file\n");
	if (!(fd = open(input, O_RDONLY)))
		return (error());
	line = NULL;
	set_t_max(max);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("done with GNL\n");
		if (!(update_max_pts(line, max)))
			return (0);
		printf("done updating pts\n");
		if (!s)
		{
			printf("ft_strdup: %s\n", ft_strdup(line));
			*s = ft_strdup(line);
		}
		else
		{
			if (!(*s = ft_strjoin(*s, "\n")))
				return (error());
			if (!(*s = ft_strjoinfree(*s, line, 'l')))
				return (error());
			printf("current string: %s\n", *s);
		}
	}
	if (ret == -1)
		return (error());
	printf("Done reading file\n");
	return (1);
}

void	set_t_max(t_max *max)
{
	max->x = 0;
	max->y = 0;
	max->z = 0;
}

/*
** Checks the length of the lines to find the maximum length.
** Also increments the number of lines.
*/

int	update_max_pts(char *line, t_max *max)
{
	int	i;
	int	height;
	int	pt_count;

	printf("update_max_pts\n");
	i = 0;
	pt_count = 0;
	while (line && line[i])
	{
		if (!((ft_isdigit(line[i])) ||
			('A' <= line[i] && line[i] <= 'F') ||
			('a' <= line[i] && line[i] <= 'f') ||
			(line[i] == ',') || (line[i] == 'x') || line[i] == 32))
					return (ft_error("Invalid character"));
		(line[i] == ',') ? g_user_set_colors = 1 : 0;
		if (ft_isdigit(line[i]) && ((i == 0) || (line[i - 1] == 32)))
		{
			(max->z < (height = ft_atoi(line + i))) ? max->z = height : 0;
			pt_count++;
		}
		i++;
	}
	(max->x < pt_count) ? max->x = pt_count : 0;
	max->y++;
	return (1);
}
