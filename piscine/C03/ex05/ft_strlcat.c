/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 03:32:36 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/30 18:47:38 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int		get_len(char *str)
{
	unsigned int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int len_d;
	unsigned int len_s;
	unsigned int i;
	unsigned int j;

	len_d = get_len(dest);
	len_s = get_len(src);
	if (size < len_d)
		return (len_s + size);
	i = 0;
	j = len_d;
	while (j + 1 < size && src[i] != 0)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return (len_s + len_d);
}
