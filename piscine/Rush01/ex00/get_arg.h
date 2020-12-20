/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:11:51 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/28 22:22:06 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ARG_H
# define GET_ARG_H

# include <stdbool.h>

bool		check_arg(int **input);
bool		read_arg(char *ptr, int **input);

#endif
