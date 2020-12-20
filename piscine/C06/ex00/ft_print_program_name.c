/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 00:25:23 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/03 00:27:41 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int len;

	if (argc != 1)
		return (1);
	len = 0;
	while (argv[0][len] != 0)
		len++;
	write(1, argv[0], len);
	write(1, "\n", 1);
	return (0);
}
