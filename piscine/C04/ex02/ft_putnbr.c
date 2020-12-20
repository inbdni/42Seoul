/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:35:12 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/30 21:53:05 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_nbr(int nb)
{
	char c;

	if (nb == 0)
		return ;
	if (nb < 0)
		c = (nb % 10 * -1) + '0';
	else
		c = (nb % 10) + '0';
	ft_nbr(nb / 10);
	write(STDOUT_FILENO, &c, 1);
}

void		ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write(STDOUT_FILENO, "0", 1);
		return ;
	}
	if (nb < 0)
		write(STDOUT_FILENO, "-", 1);
	ft_nbr(nb);
}
