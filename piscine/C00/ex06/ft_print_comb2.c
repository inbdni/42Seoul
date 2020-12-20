/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:35:54 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/23 16:06:01 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_comb2(void)
{
	int		num1;
	int		num2;
	char	c[5];

	c[2] = ' ';
	num1 = 0;
	while (num1 < 100)
	{
		c[0] = num1 / 10 + '0';
		c[1] = num1 % 10 + '0';
		num2 = num1 + 1;
		while (num2 < 100)
		{
			c[3] = num2 / 10 + '0';
			c[4] = num2 % 10 + '0';
			write(STDOUT_FILENO, &c, sizeof(c));
			if (!(num1 == 98 && num2 == 99))
				write(STDOUT_FILENO, ", ", 2);
			num2++;
		}
		num1++;
	}
}
