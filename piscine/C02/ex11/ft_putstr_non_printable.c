/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 04:34:00 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/25 19:59:28 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char g_hexa[16];

void		reset_hexa(void)
{
	int idx;

	idx = 0;
	while (idx < 10)
	{
		g_hexa[idx] = idx + '0';
		idx++;
	}
	while (idx < 16)
	{
		g_hexa[idx] = idx - 10 + 'a';
		idx++;
	}
}

void		print_char(char c)
{
	write(STDOUT_FILENO, &c, sizeof(c));
}

void		print_hexa(int c)
{
	char buf[2];

	if (c < 0)
		c += 256;
	buf[0] = g_hexa[c / 16];
	buf[1] = g_hexa[c % 16];
	write(STDOUT_FILENO, "\\", 1);
	write(STDOUT_FILENO, buf, 2);
}

void		ft_putstr_non_printable(char *str)
{
	int	idx;
	int	temp;

	reset_hexa();
	idx = 0;
	while (1)
	{
		temp = str[idx];
		if (temp == 0)
			break ;
		if (temp >= 32 && temp <= 126)
			print_char(temp);
		else
			print_hexa(temp);
		idx++;
	}
}
