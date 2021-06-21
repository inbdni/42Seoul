/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:28:50 by jimbaek           #+#    #+#             */
/*   Updated: 2021/06/19 04:29:16 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_base(char conversion)
{
	if (conversion == 'd' || conversion == 'i' || conversion == 'u')
		return ("0123456789");
	else if (conversion == 'p' || conversion == 'x')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}
