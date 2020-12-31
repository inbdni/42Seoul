/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:06:26 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/31 23:13:45 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *restrict dst, const char *restrict src, \
			size_t dstsize)
{
	size_t idx;
	size_t len;

	len = 0;
	if (!src)
	{
		return (0);
	}
	while (src[len])
	{
		len++;
	}
	if (dstsize > 0)
	{
		idx = 0;
		while (idx + 1 < dstsize && src[idx])
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = 0;
	}
	return (len);
}
