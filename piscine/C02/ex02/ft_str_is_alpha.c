/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 23:02:15 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/25 20:06:48 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int idx;

	idx = 0;
	while (1)
	{
		if (str[idx] == '\0')
			break ;
		if (!(str[idx] >= 'A' && str[idx] <= 'Z'))
			if (!(str[idx] >= 'a' && str[idx] <= 'z'))
				return (0);
		idx++;
	}
	return (1);
}
