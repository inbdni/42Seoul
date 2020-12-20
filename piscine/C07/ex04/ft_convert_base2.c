/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:18:26 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/07 20:36:09 by jimbaek          ###   ########.fr       */
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

void		check_prefix(char *nbr, int *cnt, int *i)
{
	while (nbr[*i] != 0)
	{
		if (nbr[*i] == '+')
			*i += 1;
		else if (nbr[*i] == '-')
		{
			*cnt += 1;
			*i += 1;
		}
		else
			break ;
	}
	if (*cnt % 2 == 0)
		*cnt = 1;
	else
		*cnt = -1;
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

int			check_size(int nbr, int len)
{
	int size;

	size = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		size++;
	while (nbr != 0)
	{
		size++;
		nbr /= len;
	}
	return (size);
}
