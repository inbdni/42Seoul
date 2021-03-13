/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:14:04 by jimbaek           #+#    #+#             */
/*   Updated: 2021/03/14 03:55:02 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			read_file(int fd, char **data)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		res;

	res = read(fd, buffer, BUFFER_SIZE);
	if (res <= 0)
		return (res);
	buffer[res] = 0;
	tmp = ft_strjoin(*data, buffer);
	free(*data);
	*data = tmp;
	return (res);
}

int			find_newline(char **data, char **line)
{
	int		idx;

	idx = ft_strchr(*data, '\n');
	if (idx >= 0)
	{
		get_newline(data, line, idx);
		return (1);
	}
	return (0);
}

void		get_newline(char **data, char **line, int idx)
{
	char	*tmp;

	(*data)[idx] = 0;
	if (idx)
		*line = ft_strdup(*data);
	else
		*line = ft_strdup("");
	tmp = ft_strdup(*data + idx + 1);
	free(*data);
	*data = tmp;
}

int			after_read_all(char **data, char **line)
{
	int		res;

	if (*data)
	{
		res = find_newline(data, line);
		if (res)
			return (1);
		*line = *data;
		*data = NULL;
		return (0);
	}
	else
	{
		*line = ft_strdup("");
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	static char	*data = NULL;
	int			res;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while (1)
	{
		res = read_file(fd, &data);
		if (res <= 0)
			break ;
		res = find_newline(&data, line);
		if (res != 0)
			return (res);
	}
	if (res == -1)
		return (-1);
	return (after_read_all(&data, line));
}
