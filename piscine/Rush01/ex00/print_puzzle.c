/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_puzzle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:49:09 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/28 22:21:09 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_puzzle.h"

int		print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

void	print_puzzle(int **puzzle)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = puzzle[i][j] + '0';
			write(1, &c, 1);
			if (j == 3)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			j++;
		}
		i++;
	}
}
