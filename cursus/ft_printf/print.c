/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:26:21 by jimbaek           #+#    #+#             */
/*   Updated: 2021/06/19 23:11:27 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_chr(t_info *info, int data)
{
	int	res;

	res = 0;
	if (info->minus)
		res += put_chr(data);
	res += put_empty(info->zero, info->width - 1);
	if (!info->minus)
		res += put_chr(data);
	return (res);
}

int		print_str(t_info *info, char *data)
{
	int len;
	int res;

	if (!data)
		data = "(null)";
	len = ft_strlen(data);
	if (info->precision > -1 && info->precision < len)
		len = info->precision;
	res = 0;
	if (info->minus)
		res += put_str(data, len);
	res += put_empty(info->zero, info->width - len);
	if (!info->minus)
		res += put_str(data, len);
	return (res);
}

int		print_nbr(t_info *info, unsigned long long data)
{
	char	*buf;
	int		buflen;
	int		res;

	check_info_nbr(info, data);
	buflen = put_nbr(info, data, &buf);
	res = 0;
	if (info->minus)
		res += put_str(buf, buflen);
	res += put_empty(info->zero, info->width - (buflen));
	if (!info->minus)
		res += put_str(buf, buflen);
	free(buf);
	return (res);
}