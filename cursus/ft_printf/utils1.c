/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:36:17 by jimbaek           #+#    #+#             */
/*   Updated: 2021/06/19 17:57:41 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i++])
		len++;
	return (len);
}

int		ft_nbrlen(unsigned long long nbr, int base)
{
	int	len;

	len = 0;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int		ft_prelen(unsigned long long data, int conversion)
{
	if ((conversion == 'd' || conversion == 'i') && (int)data < 0)
		return (1);
	if (conversion == 'p')
		return (2);
	return (0);
}