/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 03:45:50 by jimbaek           #+#    #+#             */
/*   Updated: 2021/03/14 03:55:47 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

int			ft_strchr(const char *s, char c)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == c)
		{
			return (idx);
		}
		idx++;
	}
	return (-1);
}

char		*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

char		*ft_strjoin(const char *str, const char *buf)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	if (!buf)
		return (NULL);
	if (!str)
		return (ft_strdup(buf));
	size = ft_strlen(str) + ft_strlen(buf) + 1;
	tmp = (char *)malloc(sizeof(char) * size);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
		tmp[i++] = str[j++];
	j = 0;
	while (buf[j])
		tmp[i++] = buf[j++];
	tmp[i] = 0;
	return (tmp);
}
