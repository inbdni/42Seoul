/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:34:02 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/25 22:33:36 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			is_upcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int			is_lowcase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char		is_word(char c, int gap, int *is_start)
{
	if (!is_num(c) && !is_upcase(c) && !is_lowcase(c))
	{
		*is_start = 1;
	}
	else
	{
		if (*is_start && is_lowcase(c))
			c -= gap;
		else if (!(*is_start) && is_upcase(c))
			c += gap;
		*is_start = 0;
	}
	return (c);
}

char		*ft_strcapitalize(char *str)
{
	int		idx;
	int		gap;
	int		is_start;
	char	res;

	idx = 0;
	gap = (int)('a' - 'A');
	is_start = 1;
	while (1)
	{
		if (str[idx] == '\0')
			break ;
		res = is_word(str[idx], gap, &is_start);
		str[idx] = res;
		idx++;
	}
	return (str);
}
