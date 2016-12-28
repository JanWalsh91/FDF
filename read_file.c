/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:01:12 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/28 11:46:12 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** Reads the input with get_next_line and checks validity of lines and points.
** Puts the contents of the file in char *data->s.
** Determines ref.x and ref.y for allocating memory later on.
** Sets color_input to 1 if a comma is found.
*/

static int	check_line(char *line, t_data *d);
static int	too_small(t_data *d);

int			read_file(char *input, t_data *d)
{
	int		fd;
	char	*line;
	int		ret;

	if (!(fd = open(input, O_RDONLY)))
		return (return_error());
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(check_line(line, d)))
			return (0);
		if (!d->s)
			d->s = ft_strdup(line);
		else
		{
			if (!(d->s = ft_strjoin(d->s, "\n")))
				return (return_error());
			if (!(d->s = ft_strjoinfree(d->s, line, 'b')))
				return (return_error());
		}
	}
	close(fd);
	if (ret == -1)
		return (return_error());
	return (too_small(d) ? ft_error("Not enough points in file") : 1);
}

/*
** Checks char values.
*/

static int	check_line(char *line, t_data *d)
{
	int	i;
	int	pt_count;

	i = 0;
	pt_count = 0;
	while (line && line[i])
	{
		if (!((ft_isdigit(line[i])) ||
					('A' <= line[i] && line[i] <= 'F') ||
					('a' <= line[i] && line[i] <= 'f') ||
					(line[i] == ',') || (line[i] == 'x') ||
					(line[i] == '-') ||
					line[i] == 32))
			return (ft_error("Invalid character"));
		(line[i] == ',') ? d->color_input = 1 : 0;
		if ((ft_isdigit(line[i]) || line[i] == '-') &&
				((i == 0) || (line[i - 1] == 32)))
			pt_count++;
		i++;
	}
	d->ref.y++;
	(!d->ref.x) ? d->ref.x = pt_count : 0;
	return ((d->ref.x != pt_count || !pt_count) ?
			ft_error("Invalid line length") : 1);
}

/*
** Checks if there are less than 2 points.
*/

static int	too_small(t_data *d)
{
	if (!d->s || (d->ref.x == 1 && d->ref.y == 1))
		return (1);
	return (0);
}
