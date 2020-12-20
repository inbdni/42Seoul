/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:01:53 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/09 15:12:35 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void		ft_putnbr(int nbr)
{
	char c;

	if (nbr == 0)
		return ;
	c = (nbr % 10) + '0';
	ft_putnbr(nbr / 10);
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void		ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		i++;
	}
}
