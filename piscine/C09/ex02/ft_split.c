/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:42:01 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/09 11:53:46 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	g_i;
unsigned int	g_size;

unsigned int		ft_find(char c, char *to_find)
{
	unsigned int i;

	i = 0;
	while (to_find[i] != 0)
	{
		if (c == to_find[i])
			return (1);
		i++;
	}
	return (0);
}

unsigned int		ft_strstr(char *str, char *to_find, unsigned int *i)
{
	unsigned int	len;

	len = 0;
	while (str[*i] != 0)
	{
		if (ft_find(str[*i], to_find) == 1)
			break ;
		*i += 1;
		len++;
	}
	return (len);
}

void				ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n - 1)
	{
		if (src[i] == 0)
			break ;
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

unsigned int		ft_strsize(char *str, char *charset, int flag, char **res)
{
	unsigned int i;
	unsigned int size;
	unsigned int s_len;

	i = 0;
	size = 0;
	while (str[i] != 0)
	{
		s_len = ft_strstr(str, charset, &i);
		if (s_len > 0)
		{
			if (flag)
				res[size] = (char *)malloc(sizeof(char) * \
						(s_len + 1));
			size++;
		}
		if (str[i] != 0)
			i++;
	}
	return (size);
}

char				**ft_split(char *str, char *charset)
{
	unsigned int	s_len;
	char			**res;

	g_size = ft_strsize(str, charset, 0, NULL);
	res = (char **)malloc(sizeof(char *) * (g_size + 1));
	g_size = ft_strsize(str, charset, 1, res);
	res[g_size] = (char *)malloc(sizeof(char) * 1);
	g_size = 0;
	while (str[g_i] != 0)
	{
		s_len = ft_strstr(str, charset, &g_i);
		if (s_len > 0)
		{
			ft_strncpy(res[g_size], str + g_i - s_len, s_len + 1);
			g_size++;
		}
		if (str[g_i] != 0)
			g_i++;
	}
	res[g_size] = NULL;
	return (res);
}
