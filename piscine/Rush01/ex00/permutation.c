/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:50:35 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/28 22:37:30 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "permutation.h"

int g_i;
int g_num[] = {1, 2, 3, 4};
int **g_per;

void		per_alloc(void)
{
	int i;

	g_per = (int **)malloc(24 * sizeof(int *));
	i = 0;
	while (i < 24)
	{
		g_per[i] = (int *)malloc(4 * sizeof(int));
		i++;
	}
}

void		per_store(void)
{
	int k;

	k = 0;
	while (k < 4)
	{
		g_per[g_i][k] = g_num[k];
		k++;
	}
	g_i++;
}

void		per_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		per_do(int n, int r, int depth)
{
	int i;

	if (r == depth)
	{
		per_store();
		return ;
	}
	i = depth;
	while (i < n)
	{
		per_swap(&g_num[i], &g_num[depth]);
		per_do(n, r, depth + 1);
		per_swap(&g_num[i], &g_num[depth]);
		i++;
	}
}

int			**permutation(void)
{
	per_alloc();
	per_do(4, 4, 0);
	return (g_per);
}
