/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:21:40 by jimbaek           #+#    #+#             */
/*   Updated: 2021/06/21 21:06:35 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_data(va_list ap, t_info *info)
{
	char	conv;
	int		res;

	conv = info->conversion;
	if (conv == '%')
		res = print_chr(info, '%');
	else if (conv == 'c')
		res = print_chr(info, va_arg(ap, int));
	else if (conv == 's')
		res = print_str(info, va_arg(ap, char *));
	else if (conv == 'd' || conv == 'i')
		res = print_nbr(info, va_arg(ap, int));
	else if (conv == 'u' || conv == 'x' || conv == 'X')
		res = print_nbr(info, va_arg(ap, unsigned int));
	else if (conv == 'p')
		res = print_nbr(info, va_arg(ap, unsigned long long));
	else
		res = 0;
	return (res);
}

int		print_format(va_list ap, char *format)
{
	t_info	info;
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			init_info(&info);
			while (format[++i] && !check_info(ap, &info, format[i]))
				continue;
			i++;
			if (!info.valid)
				break ;
			res += print_data(ap, &info);
		}
		else
			res += put_chr(format[i++]);
	}
	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	va_start(ap, format);
	res = print_format(ap, (char *)format);
	va_end(ap);
	return (res);
}
