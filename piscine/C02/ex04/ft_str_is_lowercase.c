/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 00:17:11 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/25 22:31:35 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int idx;

	idx = 0;
	while (1)
	{
		if (str[idx] == '\0')
			break ;
		if (!(str[idx] >= 'a' && str[idx] <= 'z'))
			return (0);
		idx++;
	}
	return (1);
}
