/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:25:29 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/21 22:59:44 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		rush(int x, int y)
{
	int i;
	int j;

	if (x > 0 && y > 0)
	{
		i = -1;
		while (i++ < y - 1)
		{
			j = -1;
			while (j++ < x - 1)
			{
				if (i == 0 && j == 0)
					ft_putchar('/');
				else if ((i == 0 && j == x - 1) || (i == y - 1 && j == 0))
					ft_putchar('\\');
				else if (i == y - 1 && j == x - 1)
					ft_putchar('/');
				else if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
					ft_putchar('*');
				else
					ft_putchar(' ');
			}
			ft_putchar('\n');
		}
	}
}
