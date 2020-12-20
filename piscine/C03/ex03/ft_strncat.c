/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 03:13:11 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/30 17:58:56 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int len;
	unsigned int i;

	len = 0;
	while (dest[len] != 0)
		len++;
	i = 0;
	while (i < nb && src[i] != 0)
		dest[len++] = src[i++];
	dest[len] = 0;
	return (dest);
}
