/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 03:15:15 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/30 18:10:20 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strstr(char *str, char *to_find)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[i] != 0)
	{
		res = &str[i];
		j = 0;
		while (to_find[j] != 0)
		{
			if (str[i + j] != to_find[j])
				break ;
			j++;
		}
		if (to_find[j] == 0)
			return (res);
		i++;
	}
	return (0);
}
