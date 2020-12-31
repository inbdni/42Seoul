/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:05:16 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/27 23:56:52 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	if (c == '\f' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

static int		ft_isprefix(const char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			is_neg;
	long long	result;

	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	is_neg = ft_isprefix(str[i]);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i++] - '0';
		if (result > 2147483647 && is_neg == 1)
			return (-1);
		if (result > 2147483648 && is_neg == -1)
			return (0);
	}
	return (result * is_neg);
}
