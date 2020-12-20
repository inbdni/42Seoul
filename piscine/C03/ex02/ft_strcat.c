/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 03:01:47 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/29 04:07:57 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strcat(char *dest, char *src)
{
	unsigned int len;
	unsigned int i;

	len = 0;
	while (dest[len] != 0)
		len++;
	i = 0;
	while (src[i] != 0)
		dest[len++] = src[i++];
	dest[len] = src[i];
	return (dest);
}
