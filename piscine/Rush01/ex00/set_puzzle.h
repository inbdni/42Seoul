/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_puzzle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:13:28 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/29 02:20:57 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_PUZZLE_H
# define SET_PUZZLE_H

# include <stdbool.h>
# include "permutation.h"
# include "check_puzzle.h"
# include "print_puzzle.h"

void		free_memory(int **puzzle);
bool		choose_row(int **puzzle);
bool		check_dup(int **puzzle);
bool		try_puzzle(int **puzzle, int **input);
bool		set_puzzle(int **input);

#endif
