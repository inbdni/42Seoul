/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:43:57 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/09 11:43:25 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int						ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char					*ft_strdup(char *src)
{
	int		i;
	int		len_s;
	char	*dest;

	len_s = ft_strlen(src);
	dest = (char *)malloc((len_s + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*res;

	res = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		if (res[i].copy == NULL)
			return (NULL);
		i++;
	}
	res[i].str = 0;
	return (res);
}
