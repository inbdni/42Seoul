/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:55:33 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/02 23:00:01 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_space(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	if (c == '\f' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

int			is_prefix(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int			check_base(char *base)
{
	int i;
	int j;

	if (base[0] == 0 || base[1] == 0)
		return (-1);
	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (-1);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

int			ft_atoi(char c, char *base, int len, int *result)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (base[i] == c)
		{
			*result = *result * len + i;
			return (1);
		}
		i++;
	}
	return (0);
}

int			ft_atoi_base(char *str, char *base)
{
	int i;
	int cnt_minus;
	int len;
	int result;

	i = 0;
	cnt_minus = 0;
	len = check_base(base);
	if (len < 0)
		return (0);
	result = 0;
	while (is_space(str[i]))
		i++;
	while (is_prefix(str[i]))
	{
		if (str[i] == '-')
			cnt_minus++;
		i++;
	}
	while (ft_atoi(str[i], base, len, &result) != 0)
		i++;
	if (cnt_minus % 2 == 1)
		result *= -1;
	return (result);
}
