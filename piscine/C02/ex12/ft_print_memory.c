/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:13:27 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/25 22:42:13 by jimbaek          ###   ########.fr       */
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

void		print_char(char *addr, unsigned int size)
{
	unsigned int	idx;
	int				temp;
	char			buf;

	idx = 0;
	while (idx < size)
	{
		temp = addr[idx];
		if (temp >= 32 && temp <= 126)
			buf = temp;
		else
			buf = '.';
		write(STDOUT_FILENO, &buf, 1);
		idx++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

void		print_hexa(char *addr, unsigned int size)
{
	unsigned int	idx;
	int				temp;
	char			buf[2];

	idx = 0;
	while (idx < size)
	{
		temp = addr[idx];
		if (temp < 0)
			temp += 256;
		buf[0] = g_hexa[temp / 16];
		buf[1] = g_hexa[temp % 16];
		write(STDOUT_FILENO, buf, 2);
		idx++;
		if (idx % 2 == 0)
			write(STDOUT_FILENO, " ", 1);
	}
	while (idx < 16)
	{
		if (idx % 2 == 0)
			write(STDOUT_FILENO, "  ", 2);
		else
			write(STDOUT_FILENO, "   ", 3);
		idx++;
	}
}

void		print_addr(long long addr)
{
	int			idx;
	long long	ptr;
	int			mask;
	char		buf[16];

	idx = 16;
	ptr = addr;
	mask = 0xff;
	while (idx-- > 0)
	{
		buf[idx] = g_hexa[(ptr & mask) % 16];
		ptr = ptr >> 4;
	}
	write(STDOUT_FILENO, buf, 16);
	write(STDOUT_FILENO, ": ", 2);
}

void		*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int idx;
	unsigned int gap;

	reset_hexa();
	idx = 0;
	while (idx < size)
	{
		gap = size - idx;
		print_addr((long long)&addr[idx]);
		if (gap > 16)
			gap = 16;
		print_hexa(&addr[idx], gap);
		print_char(&addr[idx], gap);
		idx += gap;
	}
	return (addr);
}
