/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:02:15 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/25 22:50:15 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcpy(char *dest, char *src)
{
	int idx;

	idx = 0;
	while (1)
	{
		dest[idx] = src[idx];
		if (src[idx] == '\0')
			break ;
		idx++;
	}
	return (dest);
}
