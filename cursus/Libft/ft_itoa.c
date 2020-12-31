/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:05:41 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/27 23:57:32 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrlen(int n)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		is_neg;
	int		index;
	int		value;
	char	*str;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	str = (char *)malloc(sizeof(char) * (ft_nbrlen(n) + is_neg + 1));
	if (str == NULL)
		return (NULL);
	index = ft_nbrlen(n) + is_neg;
	str[index] = 0;
	index--;
	while (index >= 0)
	{
		value = n % 10;
		if (value < 0)
			value *= -1;
		str[index--] = value + '0';
		n /= 10;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}
