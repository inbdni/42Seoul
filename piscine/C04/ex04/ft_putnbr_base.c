/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:24:04 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/02 18:24:43 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			check_base(char *base)
{
	int i;
	int j;

	if (base[0] == 0 || base[1] == 0)
		return (-1);
	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		j = i + 1;
		while (!base[j])
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

void		ft_putnbr(int nbr, char *base, int len)
{
	int idx;

	if (nbr == 0)
		return ;
	idx = nbr % len;
	if (idx < 0)
		idx *= -1;
	ft_putnbr(nbr / len, base, len);
	write(1, &base[idx], 1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int len;

	len = check_base(base);
	if (len < 0)
		return ;
	if (nbr == 0)
		write(1, &base[0], 1);
	if (nbr < 0)
		write(1, "-", 1);
	ft_putnbr(nbr, base, len);
}
