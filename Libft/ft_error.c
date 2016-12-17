/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:37:37 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/17 17:09:37 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Puts the error message on the error output and returns 0.
*/

#include "libft.h"

int	ft_error(char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	return (0);
}
