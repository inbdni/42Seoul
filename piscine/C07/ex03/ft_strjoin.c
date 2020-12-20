/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 03:44:40 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/09 02:53:38 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*g_res;

int			ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int			ft_total_len(int size, char **strs, int seplen)
{
	int i;
	int total;

	i = 0;
	total = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		total += seplen;
		i++;
	}
	total -= seplen;
	total++;
	return (total);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		total;

	if (size <= 0)
	{
		g_res = (char *)malloc(sizeof(char));
		return (g_res);
	}
	total = ft_total_len(size, strs, ft_strlen(sep));
	g_res = (char *)malloc(total * sizeof(char));
	i = 0;
	j = 0;
	while (i < size)
	{
		ft_strcpy(g_res + j, strs[i]);
		j += ft_strlen(strs[i]);
		i++;
		if (i == size)
			break ;
		ft_strcpy(g_res + j, sep);
		j += ft_strlen(sep);
	}
	g_res[j] = 0;
	return (g_res);
}
