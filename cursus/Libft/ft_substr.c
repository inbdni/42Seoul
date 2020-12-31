/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:06:34 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/28 00:01:03 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!s)
		return (NULL);
	size = 0;
	if (start < ft_strlen(s))
		size = ft_strlen(s) - start;
	if (size > len)
		size = len;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (j < size)
	{
		str[j++] = s[i++];
	}
	str[j] = 0;
	return (str);
}
