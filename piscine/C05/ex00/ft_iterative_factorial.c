/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:55:41 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/02 13:05:13 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int res;

	if (nb < 0)
		return (0);
	res = 1;
	while (nb > 0)
	{
		res *= nb;
		nb--;
	}
	return (res);
}
