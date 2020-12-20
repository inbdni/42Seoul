/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 00:59:45 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/25 22:33:00 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strupcase(char *str)
{
	int idx;
	int gap;

	idx = 0;
	gap = (int)('a' - 'A');
	while (1)
	{
		if (str[idx] == '\0')
			break ;
		if (str[idx] >= 'a' && str[idx] <= 'z')
			str[idx] -= gap;
		idx++;
	}
	return (str);
}
