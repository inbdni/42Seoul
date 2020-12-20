/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:41:11 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/24 21:06:58 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		rush(int x, int y)
{
	int i;
	int j;

	if (x > 0 && y > 0)
	{
		i = 0;
		while (i < y)
		{
			j = 0;
			while (j < x)
			{
				if ((i == 0 || i == y - 1) && j == 0)
					ft_putchar('A');
				else if ((i == 0 || i == y - 1) && j == x - 1)
					ft_putchar('C');
				else if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
					ft_putchar('B');
				else
					ft_putchar(' ');
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}
