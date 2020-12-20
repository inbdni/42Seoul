/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:49:11 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/30 17:12:05 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_space(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	if (c == '\f' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

int		is_prefix(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int cnt_minus;
	int result;

	i = 0;
	cnt_minus = 0;
	result = 0;
	while (is_space(str[i]))
		i++;
	while (is_prefix(str[i]))
	{
		if (str[i] == '-')
			cnt_minus++;
		i++;
	}
	while (is_num(str[i]))
		result = result * 10 + str[i++] - '0';
	if (cnt_minus % 2 == 1)
		result *= -1;
	return (result);
}
