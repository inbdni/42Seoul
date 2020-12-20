/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:03:55 by jimbaek           #+#    #+#             */
/*   Updated: 2020/12/09 04:46:35 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define EVEN(NBR)	(NBR % 2 == 0)
# define EVEN_MSG	"I have an even number of arguments.\n"
# define ODD_MSG	"I have an odd number of arguments.\n"

# include <stdbool.h>
# include <unistd.h>

typedef bool	t_bool;

void			ft_putstr(char *str);
t_bool			ft_is_even(int nbr);

#endif
