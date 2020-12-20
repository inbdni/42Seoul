/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 00:28:05 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/03 01:11:23 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int			ft_strcmp(char *s1, char *s2)
{
	int idx;

	idx = 0;
	while (s1[idx] != 0 || s2[idx] != 0)
	{
		if (s1[idx] == s2[idx])
			idx++;
		else
			return (s1[idx] - s2[idx]);
	}
	return (0);
}

void		ft_swap(char **s1, char **s2)
{
	char *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int			ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

int			main(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				ft_swap(&argv[i], &argv[j]);
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
