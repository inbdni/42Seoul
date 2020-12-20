/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:55:39 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/02 20:57:12 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_prime(int nb)
{
	long long i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (1)
	{
		if (is_prime(nb))
			return (nb);
		nb++;
	}
}
