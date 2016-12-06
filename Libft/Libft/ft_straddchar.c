/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:17:40 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/01 11:32:09 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** UNTESTED
** Allocated memory for a new string to which a char was added.
** Returns that string.
*/

#include "libft.h"

char	*ft_straddchar(char const *s, char c)
{
	char	*newstr;
	size_t	length;
	size_t	i;

	if (!c || !ft_isprint(c))
		return ((char *)s);
	length = (s) ? ft_strlen((char *)s + 2) : 2;
	if (!(newstr = ft_memalloc(sizeof(char) * length)))
		return (NULL);
	i = 0;
	while (i < length && s && s[i])
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i++] = c;
	newstr[i] = '\0';
	return (newstr);
}
