/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 00:24:30 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/25 22:32:12 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int idx;

	idx = 0;
	while (1)
	{
		if (str[idx] == '\0')
			break ;
		if (!(str[idx] >= 32 && str[idx] <= 126))
			return (0);
		idx++;
	}
	return (1);
}
