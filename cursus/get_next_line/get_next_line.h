/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:14:06 by jimbaek           #+#    #+#             */
/*   Updated: 2021/03/14 03:59:51 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int			ft_strlen(const char *s);
int			ft_strchr(const char *s, char c);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *str, const char *buf);

int			read_file(int fd, char **data);
int			find_newline(char **data, char **line);
void		get_newline(char **data, char **line, int idx);
int			after_read_all(char **data, char **line);
int			get_next_line(int fd, char **line);

#endif
