/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 23:30:21 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/30 18:34:14 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int idx;

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
