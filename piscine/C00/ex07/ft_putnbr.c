/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:15:12 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/23 17:01:30 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

int			ft_check_size(int nb)
{
	int size;

	if (nb == 0)
		return (1);
	size = 0;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

void		ft_putmin(void)
{
	write(STDOUT_FILENO, "-2147483648", 11);
}

void		ft_putnormal(int nb)
{
	int		i;
	int		size;
	char	num[10];

	size = ft_check_size(nb);
	i = size - 1;
	while (i >= 0)
	{
		num[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	write(STDOUT_FILENO, &num, size);
}

void		ft_putnbr(int nb)
{
	if (nb == INT_MIN)
		ft_putmin();
	else if (nb < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		nb *= -1;
	}
	ft_putnormal(nb);
}
