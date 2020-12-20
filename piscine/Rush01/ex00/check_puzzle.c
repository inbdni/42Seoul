/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_puzzle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:30:40 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/28 22:21:51 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_puzzle.h"

bool		check_up(int **puzzle, int **input)
{
	int i;
	int j;
	int max;
	int cnt;
	int goal;

	i = -1;
	while (i++ < 3)
	{
		max = 0;
		cnt = 0;
		goal = input[0][i];
		j = -1;
		while (j++ < 3)
		{
			if (puzzle[j][i] > max)
			{
				max = puzzle[j][i];
				cnt++;
			}
		}
		if (cnt != goal)
			return (false);
	}
	return (true);
}

bool		check_down(int **puzzle, int **input)
{
	int i;
	int j;
	int max;
	int cnt;
	int goal;

	i = -1;
	while (i++ < 3)
	{
		max = 0;
		cnt = 0;
		goal = input[1][i];
		j = 4;
		while (j-- > 0)
		{
			if (puzzle[j][i] > max)
			{
				max = puzzle[j][i];
				cnt++;
			}
		}
		if (cnt != goal)
			return (false);
	}
	return (true);
}

bool		check_left(int **puzzle, int **input)
{
	int i;
	int j;
	int max;
	int cnt;
	int goal;

	i = -1;
	while (i++ < 3)
	{
		max = 0;
		cnt = 0;
		goal = input[2][i];
		j = -1;
		while (j++ < 3)
		{
			if (puzzle[i][j] > max)
			{
				max = puzzle[i][j];
				cnt++;
			}
		}
		if (cnt != goal)
			return (false);
	}
	return (true);
}

bool		check_rignt(int **puzzle, int **input)
{
	int i;
	int j;
	int max;
	int cnt;
	int goal;

	i = -1;
	while (i++ < 3)
	{
		max = 0;
		cnt = 0;
		goal = input[3][i];
		j = 4;
		while (j-- > 0)
		{
			if (puzzle[i][j] > max)
			{
				max = puzzle[i][j];
				cnt++;
			}
		}
		if (cnt != goal)
			return (false);
	}
	return (true);
}

bool		check_puzzle(int **puzzle, int **input)
{
	if (!check_up(puzzle, input))
		return (false);
	if (!check_down(puzzle, input))
		return (false);
	if (!check_left(puzzle, input))
		return (false);
	if (!check_rignt(puzzle, input))
		return (false);
	return (true);
}
