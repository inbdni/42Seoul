/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:06:08 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/28 01:38:43 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *restrict dst, \
			const void *restrict src, int c, size_t n)
{
	size_t	i;
	size_t	j;

	if (!src && n <= 0)
		return (NULL);
	i = 0;
	j = 0;
	while (i < n)
	{
		((char *)dst)[j] = ((char *)src)[i];
		if (((char *)src)[i] == (char)c)
		{
			j++;
			return (dst + j);
		}
		i++;
		j++;
	}
	while (i < n)
		((char *)dst)[j] = 0;
	return (NULL);
}
