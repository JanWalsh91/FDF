/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:00:07 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/06 17:51:32 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Reads the input with get_next_line and checks for 
*/

int	check_file(char *input)
{
	int		fd;
	char	*line;
	char	*s;
	int		pts_per_line;

	if (!(fd = open(input, O_RDONLY)))
		return (error());
	line = NULL;
	if (get_next_line(fd, &line) == -1)
		return (ft_error("Error reading file"));
	if (!line)
		return (ft_error("File empty"));
	pts_per_line = get_pts_num(ft_strsplit(line, ' '));
	s = NULL;
	s = ft_strjoin(line, "\n");
	while (get_next_line(fd, &line) > 0)
	{
		s = ft_strjoin(s, line);
		if (pts_per_line != get_pts_num(ft_strsplit(line, ' ')))
			return (ft_error("Invalid file"));
		


	}

		
}

int	get_pts_num(char **s)
{
	int	i;


	while (**s)
	{
		

	}
}

int	check

int	check_elements()
{

}
