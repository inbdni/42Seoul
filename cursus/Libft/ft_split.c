/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:06:20 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/31 23:39:08 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cntword(char const *s, char c)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	num;
	unsigned int	size;

	i = 0;
	len = 0;
	num = 0;
	size = ft_strlen(s);
	while (i <= size)
	{
		if (s[i] == c || s[i] == 0)
		{
			if (len != 0)
				num++;
			len = 0;
		}
		else
		{
			len++;
		}
		i++;
	}
	return (num);
}

static int		ft_cpyword(char **split, char const *s, char c)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	start = 0;
	while (i < ft_cntword(s, c))
	{
		len = 0;
		while (s[start + len] != c && s[start + len])
			len++;
		if (len != 0)
		{
			if ((split[i] = ft_substr(s, start, len)) == NULL)
			{
				while (i > 0)
					free(split[i-- - 1]);
				return (-1);
			}
			i++;
		}
		start += len + 1;
	}
	split[i] = 0;
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_cntword(s, c) + 1));
	if (!str)
		return (NULL);
	if (ft_cpyword(str, s, c) != 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
