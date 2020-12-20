/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 05:20:52 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/07 17:40:20 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

int				is_space(char c);
void			check_prefix(char *nbr, int *cnt, int *i);
int				check_base(char *base);
int				check_size(int nbr, int len);

int				ft_atoi(char c, char *base, int len, long long *result)
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

long long		ft_atoi_base(char *nbr, char *base, int *is_over)
{
	int			i;
	int			cnt_minus;
	int			len;
	long long	result;

	i = 0;
	cnt_minus = 0;
	len = check_base(base);
	result = 0;
	while (is_space(nbr[i]))
		i++;
	check_prefix(nbr, &cnt_minus, &i);
	while (ft_atoi(nbr[i], base, len, &result) != 0)
	{
		if (result * cnt_minus < INT_MIN || result * cnt_minus > INT_MAX)
		{
			*is_over = 1;
			return (0);
		}
		i++;
	}
	if (cnt_minus == -1)
		result *= -1;
	return (result);
}

char			ft_itoa(int nbr, char *base, int len)
{
	int		i;
	char	c;

	i = nbr % len;
	if (i < 0)
		i *= -1;
	c = base[i];
	return (c);
}

void			ft_itoa_base(int nbr, char *base, char *result, int size)
{
	int len;
	int idx;

	len = check_base(base);
	idx = size - 1;
	result[idx] = '\0';
	idx--;
	if (nbr == 0)
		result[idx] = base[0];
	if (nbr < 0)
		result[0] = '-';
	while (nbr != 0)
	{
		result[idx] = ft_itoa(nbr, base, len);
		nbr /= len;
		idx--;
	}
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			is_over;
	long long	n;
	int			size;
	char		*result;

	is_over = 0;
	if (check_base(base_from) < 0 || check_base(base_to) < 0)
		return (NULL);
	n = ft_atoi_base(nbr, base_from, &is_over);
	if (is_over)
		return (NULL);
	size = check_size((int)n, check_base(base_to)) + 1;
	result = (char *)malloc(sizeof(char) * size);
	ft_itoa_base(n, base_to, result, size);
	return (result);
}
