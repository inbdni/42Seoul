/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_puzzle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:49:42 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/29 02:22:54 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_puzzle.h"

int **g_ptr;
int g_first;
int g_second;
int g_third;
int g_forth;

void		free_memory(int **puzzle)
{
	int i;

	i = -1;
	while (i++ < 3)
		free(puzzle[i]);
	free(puzzle);
	i = -1;
	while (i++ < 23)
		free(g_ptr[i]);
	free(g_ptr);
}

bool		choose_row(int **puzzle)
{
	if (g_first >= 24)
		return (false);
	puzzle[0] = g_ptr[g_first];
	puzzle[1] = g_ptr[g_second];
	puzzle[2] = g_ptr[g_third];
	puzzle[3] = g_ptr[g_forth];
	g_forth++;
	if (g_forth == 24)
	{
		g_forth = 0;
		g_third++;
		if (g_third == 24)
		{
			g_third = 0;
			g_second++;
			if (g_second == 24)
			{
				g_second = 0;
				g_first++;
			}
		}
	}
	return (true);
}

bool		check_dup(int **puzzle)
{
	int i;
	int j;
	int val;
	int used[4];

	i = -1;
	while (i++ < 3)
	{
		j = -1;
		while (j++ < 3)
			used[j] = 0;
		j = -1;
		while (j++ < 3)
		{
			val = puzzle[j][i];
			if (used[val - 1])
				return (false);
			used[val - 1] = 1;
		}
	}
	return (true);
}

bool		try_puzzle(int **puzzle, int **input)
{
	while (1)
	{
		if (!choose_row(puzzle))
			return (false);
		if (!check_dup(puzzle))
			continue;
		if (check_puzzle(puzzle, input))
			return (true);
	}
	return (false);
}

bool		set_puzzle(int **input)
{
	int i;
	int **puzzle;

	g_ptr = permutation();
	puzzle = (int **)malloc(4 * sizeof(int *));
	i = 0;
	while (i < 4)
	{
		puzzle[i] = (int *)malloc(4 * sizeof(int));
		i++;
	}
	if (try_puzzle(puzzle, input))
	{
		print_puzzle(puzzle);
		return (true);
	}
	return (false);
}
