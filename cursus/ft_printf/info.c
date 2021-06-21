/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:25:34 by jimbaek           #+#    #+#             */
/*   Updated: 2021/06/21 17:46:55 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->valid = 0;
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->precision = -1;
	info->conversion = 0;
}

void	check_width_and_precision(va_list ap, t_info *info, char c)
{
	if (c == '*')
	{
		if (info->precision == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->precision = va_arg(ap, int);
	}
	else
	{
		if (info->precision == -1)
			info->width = info->width * 10 + c - '0';
		else
			info->precision = info->precision * 10 + c - '0';
	}
}

int		check_info(va_list ap, t_info *info, char c)
{
	if (c == '-')
		info->minus = 1;
	else if (!info->width && info->precision == -1 && c == '0')
		info->zero = 1;
	else if (c == '.')
		info->precision = 0;
	else if (c == '*' || ft_isdigit(c))
		check_width_and_precision(ap, info, c);
	else if (c == '%' || ft_isalpha(c))
	{
		info->valid = 1;
		info->conversion = c;
		if (info->minus)
			info->zero = 0;
		if (info->precision > -1 && info->conversion != '%')
			info->zero = 0;
		return (1);
	}
	return (0);
}

void	check_info_nbr(t_info *info, unsigned long long data)
{
	int	conv;

	conv = info->conversion;
	info->nbr_sign = 1;
	if ((conv == 'd' || conv == 'i') && (int)data < 0)
		info->nbr_sign = -1;
	info->nbr_base = 10;
	if (conv == 'p' || conv == 'x' || conv == 'X')
		info->nbr_base = 16;
	info->nbr_prefix = 0;
	if ((conv == 'd' || conv == 'i') && (int)data < 0)
		info->nbr_prefix = 1;
	if (conv == 'p')
		info->nbr_prefix = 2;
}
