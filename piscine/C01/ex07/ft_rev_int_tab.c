/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:23:50 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/23 22:12:17 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		ft_rev_int_tab(int *tab, int size)
{
	int idx;
	int temp;
	int max;

	if (size <= 0)
		return ;
	idx = 0;
	max = (size - 1) / 2;
	while (idx <= max)
	{
		temp = tab[idx];
		tab[idx] = tab[size - idx - 1];
		tab[size - idx - 1] = temp;
		idx++;
	}
}
