/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_puzzle.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:16:39 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/28 22:18:24 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_PUZZLE_H
# define CHECK_PUZZLE_H

# include <stdbool.h>

bool		check_up(int **puzzle, int **input);
bool		check_down(int **puzzle, int **input);
bool		check_left(int **puzzle, int **input);
bool		check_right(int **puzzle, int **input);
bool		check_puzzle(int **puzzle, int **input);

#endif
