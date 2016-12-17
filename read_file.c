/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:01:12 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/17 15:57:43 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Reads the input with get_next_line and checks validity of lines and points.
** Puts the contents of the file in char *data->s.
** Determines ref.x and ref.y for allocating memory later on.
*/

/*
** Redo read_file without get_next_line.
*/

int	read_file(char *input, t_data *data)
{
	int		fd;
	char	*line;
	int		ret;

	printf("read_file\n");
	if (!(fd = open(input, O_RDONLY)))
		return (error());
	line = NULL;
	set_default_values(data);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(check_line(line, data)))
			return (0);
		if (!data->s)
			data->s = ft_strdup(line);
		else
		{
			if (!(data->s = ft_strjoin(data->s, "\n")))
				return (error());
			if (!(data->s = ft_strjoinfree(data->s, line, 'l')))
				return (error());
		}
	}
	if (!data->s)
		return (ft_error("file empty"));
	return ((ret == -1) ? error() : 1);
}

/*
** Checks char values.
*/

int	check_line(char *line, t_data *d)
{
	int	i;
	int	pt_count;

	printf("check_line\n");
	i = 0;
	pt_count = 0;
	while (line && line[i])
	{
		if (!((ft_isdigit(line[i])) ||
					('A' <= line[i] && line[i] <= 'F') ||
					('a' <= line[i] && line[i] <= 'f') ||
					(line[i] == ',') ||
					(line[i] == 'x') ||
					line[i] == 32))
			return (ft_error("Invalid character"));
		(line[i] == ',') ? d->color_input = 1 : 0;
		if (ft_isdigit(line[i]) && ((i == 0) || (line[i - 1] == 32)))
			pt_count++;
		i++;
	}
	d->ref.y++;
	(!d->ref.x) ? d->ref.x = pt_count : 0;
	//d->ref.x != pt_count ? d->ref.x = pt_count : 0;
	return ((d->ref.x != pt_count || !pt_count) ?
			ft_error("line count incorrect") : 1);
}
