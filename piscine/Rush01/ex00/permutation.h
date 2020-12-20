/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:10:15 by jimbaek           #+#    #+#             */
/*   Updated: 2020/11/28 22:28:22 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERMUTATION_H
# define PERMUTATION_H

# include <stdlib.h>

void		per_alloc(void);
void		per_store(void);
void		per_swap(int *a, int *b);
void		per_do(int n, int r, int depth);
int			**permutation(void);

#endif
