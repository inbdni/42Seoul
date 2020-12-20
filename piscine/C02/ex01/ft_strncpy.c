/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:47:49 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/26 01:35:57 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int idx;

	idx = 0;
	if (n > 0)
	{
		while (idx < n)
		{
			if (src[idx] == '\0')
				break ;
			dest[idx] = src[idx];
			idx++;
		}
		while (idx < n)
		{
			dest[idx] = '\0';
			idx++;
		}
	}
	return (dest);
}
