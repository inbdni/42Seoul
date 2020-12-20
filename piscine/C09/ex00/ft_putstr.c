/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:36:11 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/23 22:28:26 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putstr(char *str)
{
	int idx;

	idx = 0;
	while (1)
	{
		if (str[idx] == '\0')
			break ;
		write(STDOUT_FILENO, &str[idx], sizeof(char));
		idx++;
	}
}
