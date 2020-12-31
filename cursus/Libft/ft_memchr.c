/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:06:09 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/27 23:59:55 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*mem;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == c)
		{
			mem = ((char *)s) + i;
			return (mem);
		}
		i++;
	}
	return (NULL);
}
