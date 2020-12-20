/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:18:31 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/23 17:00:32 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_comb(void)
{
	int		n;
	char	num[3];

	n = 12;
	while (n < 790)
	{
		num[0] = n / 100 + '0';
		num[1] = n % 100 / 10 + '0';
		num[2] = n % 10 + '0';
		n++;
		if ((num[0] >= num[1]) || (num[1] >= num[2]))
			continue;
		write(STDOUT_FILENO, &num, sizeof(num));
		if (n != 790)
			write(STDOUT_FILENO, ", ", 2);
	}
}
