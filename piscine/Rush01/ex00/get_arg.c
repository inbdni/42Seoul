/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongilee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:20:17 by dongilee          #+#    #+#             */
/*   Updated: 2020/12/02 23:59:49 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_arg.h"

bool		check_arg(int **input)
{
	int i;
	int j;
	int sum;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (input[i][j] < 1 || input[i][j] > 4)
				return (false);
			sum = input[i][j] + input[i + 1][j];
			if (sum < 3 || sum > 5)
				return (false);
			j++;
		}
		i += 2;
	}
	return (true);
}

bool		read_arg(char *ptr, int **input)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while (i++ < 3)
	{
		j = 0;
		while (j < 4)
		{
			if (ptr[k] == '\0')
				return (false);
			else if (ptr[k] != ' ')
			{
				input[i][j] = ptr[k] - '0';
				j++;
			}
			k++;
		}
	}

	if (k != 31)
		return (false);
	if (ptr[k] != '\0')
		return (false);
	return (true);
}
