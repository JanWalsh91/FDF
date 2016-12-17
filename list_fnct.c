/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fnct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:25:12 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/15 19:48:10 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_colors	*new_color_set(void)
{
	t_colors	*link;
	
	if (!(link = (t_colors *)malloc(sizeof(t_colors))))
		return (NULL);
	link->next = NULL;
	link->previous = NULL;
}

void		add_link(t_colors **start, t_colors *new)
{
	t_colors *tmp;

	tmp = *start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->previous = tmp;
}

t_colors	**next_color_set(t_colors **colors)
{
	if ((*colors)->next)
		(*colors) = (*colors)->next;
	return (colors);
}

t_colors	**previous_color_set(t_colors **colors)
{
	if ((*colors)->previous)
		(*colors) = (*colors)->previous;
	return (colors);
}

/*
void	**free_lst(t_colors **colors)
{

}
*/
