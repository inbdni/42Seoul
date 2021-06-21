/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:26:49 by jimbaek           #+#    #+#             */
/*   Updated: 2021/06/21 17:28:07 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_empty(int zero, int len)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i++ < len)
	{
		if (zero)
			res += put_chr('0');
		else
			res += put_chr(' ');
	}
	return (res);
}

int		put_chr(int data)
{
	char	c;

	c = data;
	write(1, &c, 1);
	return (1);
}

int		put_str(char *data, int len)
{
	write(1, data, len);
	return (len);
}

int		put_nbr(t_info *info, unsigned long long data, char **buf)
{
	int	buflen;
	int res;

	data *= info->nbr_sign;
	buflen = ft_nbrlen(data, info->nbr_base);
	if (data == 0 && info->precision != 0)
		buflen = 1;
	if (buflen < info->precision)
		buflen = info->precision;
	res = info->nbr_prefix + buflen;
	if (res < info->width && !info->minus && info->zero && info->nbr_sign == -1)
		res = info->width;
	(*buf) = (char *)malloc(sizeof(char) * res + 1);
	if (!(*buf))
		return (0);
	put_nbr_data(info, data, res, buf);
	return (res);
}

void	put_nbr_data(t_info *info, unsigned long long data, int len, char **buf)
{
	int i;

	i = len - 1;
	while (data)
	{
		(*buf)[i--] = get_base(info->conversion)[data % info->nbr_base];
		data /= info->nbr_base;
	}
	while (i >= 0)
		(*buf)[i--] = '0';
	if (info->nbr_prefix == 1)
		(*buf)[0] = '-';
	if (info->nbr_prefix == 2)
		(*buf)[1] = 'x';
	(*buf)[len] = 0;
}
