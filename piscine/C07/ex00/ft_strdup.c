/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 01:52:58 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/07 19:07:04 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char		*ft_strdup(char *src)
{
	int		i;
	int		len_s;
	char	*dest;

	len_s = ft_strlen(src);
	dest = (char *)malloc((len_s + 1) * sizeof(char));
	i = 0;
	while (i < len_s)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
