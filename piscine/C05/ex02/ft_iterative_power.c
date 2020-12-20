/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:13:52 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/02 14:31:41 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int res;

	if (power < 0)
		return (0);
	i = 0;
	res = 1;
	while (i++ < power)
		res *= nb;
	return (res);
}
