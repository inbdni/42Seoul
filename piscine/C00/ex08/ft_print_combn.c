/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:14:33 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/23 16:56:55 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char g_arr[10];
char g_result[10];

int			ft_check_last(int c)
{
	if (g_result[0] == (10 - c) + '0')
		return (1);
	else
		return (0);
}

void		ft_print(int c)
{
	write(STDOUT_FILENO, &g_result, c);
	if (!ft_check_last(c))
		write(STDOUT_FILENO, ", ", 2);
}

void		ft_comb(int n, int r, int c)
{
	if (r == 0)
	{
		ft_print(c);
		return ;
	}
	else if (n < r)
	{
		return ;
	}
	else
	{
		g_result[c - r] = g_arr[10 - n];
		ft_comb(n - 1, r - 1, c);
		ft_comb(n - 1, r, c);
	}
}

void		ft_print_combn(int n)
{
	int i;

	i = 0;
	while (i < 10)
	{
		g_arr[i] = i + '0';
		i++;
	}
	ft_comb(10, n, n);
}
