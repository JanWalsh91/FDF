/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:57:42 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/30 13:08:13 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks for valid fd values and line.
** Finds the appropriate static buffer or creates a new one.
** If there is a newline in the static buffer, reads from it.
** Else, reads from the file.
*/

static int	read_file(t_list *p, char **line);
static int	read_buf(t_list *p, char **line);

int	get_next_line(const int fd, char **line)
{
	t_list			*p;
	static t_list	*lst;
	t_list			*new;

	if (!line || fd < 0 || fd == 1 || fd == 2)
		return (-1);
	p = lst;
	while (p && fd != (int)p->content_size)
		p = p->next;
	if (!p)
	{
		new = ft_lstnew("", 1);
		new->content_size = fd;
		ft_lstadd(&lst, new);
		p = lst;
	}
	if (!ft_strchr(p->content, '\n'))
		return (read_file(p, line));
	return (read_buf(p, line));
}

/*
** Attempts to read the file pointed to by p->fd, BUFF_SIZE characters
** at a time. Contatenates the strings into p->content.
** Repeats until a newline is found.
** If the end of the file is reached, checks if the static buffer has content.
** If it does, calls on read_buf.
** Else returns 0.
*/

static int	read_file(t_list *p, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	while (!ft_strchr(p->content, '\n'))
	{
		if ((ret = read(p->content_size, &buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		if (ret != 0)
			p->content = ft_strjoinfree(p->content, buf, 'l');
		if (ret == 0)
		{
			if (*(char *)p->content)
			{
				p->content = ft_strjoin(p->content, "\n");
				return (read_buf(p, line));
			}
			return (0);
		}
	}
	return (read_buf(p, line));
}

/*
** Attempts to read from the static buffer. If a newline is found, copy into
** line until the newline and returns 1. Increments the static buffer.
** If no \n is found, copy the whole buffer and read from the file.
*/

static int	read_buf(t_list *p, char **line)
{
	char	*end;
	char	*tmp;

	end = ft_strchr(p->content, '\n');
	if (*end == '\n')
	{
		*end = '\0';
		end++;
		if (!(tmp = ft_strnew(ft_strlen(end))) ||
			!(*line = (char *)ft_memalloc(ft_strlen(p->content))))
			return (0);
		tmp = ft_memcpy(tmp, end, ft_strlen(end));
		*line = ft_strjoinfree(*line, p->content, 'l');
		free(p->content);
		p->content = tmp;
		return (1);
	}
	else if (end == NULL)
	{
		*line = ft_strjoinfree(*line, p->content, 'l');
		return (read_file(p, line));
	}
	return (read_file(p, line));
}
