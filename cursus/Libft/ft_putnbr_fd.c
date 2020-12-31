/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:13:38 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/28 00:00:21 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr(int n, int fd, int is_neg)
{
	char c;

	if (n == 0)
		return ;
	ft_putnbr(n / 10, fd, is_neg);
	c = n % 10 * is_neg + '0';
	write(fd, &c, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	int is_neg;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	is_neg = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		is_neg = -1;
	}
	ft_putnbr(n, fd, is_neg);
}
