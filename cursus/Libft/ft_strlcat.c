/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:06:25 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/28 00:00:43 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict dst, const char *restrict src, \
			size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	j;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize < dlen)
	{
		return (slen + dstsize);
	}
	i = 0;
	j = dlen;
	while (j + 1 < dstsize && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return (slen + dlen);
}
