/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:57:59 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/26 02:44:13 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	len;

	len = 0;
	while (1)
	{
		if (src[len] == '\0')
			break ;
		len++;
	}
	idx = 0;
	while (idx + 1 < size)
	{
		if (src[idx] == '\0')
			break ;
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (len);
}
