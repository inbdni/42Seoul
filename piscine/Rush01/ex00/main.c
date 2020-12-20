/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongilee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:20:17 by dongilee          #+#    #+#             */
/*   Updated: 2020/11/29 02:17:37 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_arg.h"
#include "set_puzzle.h"
#include "print_puzzle.h"

int			main(int argc, char *argv[])
{
	int		i;
	int		**input;
	char	*ptr;

	if (argc != 2)
		return (print_error());
	ptr = argv[1];
	input = (int **)malloc(4 * sizeof(int *));
	i = -1;
	while (i++ < 3)
		input[i] = (int *)malloc(4 * sizeof(int));
	if (!read_arg(ptr, input))
		return (print_error());
	if (!check_arg(input))
		return (print_error());
	if (!set_puzzle(input))
		return (print_error());
	i = -1;
	while (i++ < 3)
		free(input[i]);
	free(input);
	return (0);
}
