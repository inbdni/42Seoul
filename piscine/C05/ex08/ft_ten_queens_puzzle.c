/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:38:41 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/02 23:42:42 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_puzzle[10];
int g_cnt;

void		print_puzzle(void)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = g_puzzle[i] + '0';
		write(STDOUT_FILENO, &c, 1);
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

int			abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int			check_puzzle(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (g_puzzle[i] == g_puzzle[n])
			return (0);
		if (abs(g_puzzle[i] - g_puzzle[n]) == abs(i - n))
			return (0);
		i++;
	}
	return (1);
}

void		dfs(int n, int depth)
{
	int i;

	if (depth == n)
	{
		g_cnt++;
		print_puzzle();
	}
	i = 0;
	while (i < n)
	{
		g_puzzle[depth] = i;
		if (check_puzzle(depth) != 0)
			dfs(n, depth + 1);
		i++;
	}
}

int			ft_ten_queens_puzzle(void)
{
	dfs(10, 0);
	return (g_cnt);
}
