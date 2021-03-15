/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 04:26:01 by jimbaek           #+#    #+#             */
/*   Updated: 2021/03/15 13:33:02 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (tmp == NULL)
		return (-1);
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
		return (get_newline(data, line, idx));
	}
	return (0);
}

int			get_newline(char **data, char **line, int idx)
{
	char	*tmp;

	(*data)[idx] = 0;
	if (idx)
		*line = ft_strdup(*data);
	else
		*line = ft_strdup("");
	if (*line == NULL)
		return (-1);
	tmp = ft_strdup(*data + idx + 1);
	if (tmp == NULL)
		return (-1);
	free(*data);
	*data = tmp;
	return (1);
}

int			after_read_all(char **data, char **line)
{
	int		res;

	if (*data)
	{
		res = find_newline(data, line);
		if (res != 0)
			return (res);
		*line = *data;
		*data = NULL;
		return (0);
	}
	else
	{
		*line = ft_strdup("");
		if (*line == NULL)
			return (-1);
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	static char	*data[MAX_OPEN];
	int			res;

	if (fd < 0 || fd >= MAX_OPEN || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while (1)
	{
		res = read_file(fd, &data[fd]);
		if (res <= 0)
			break ;
		res = find_newline(&data[fd], line);
		if (res != 0)
			return (res);
	}
	if (res == -1)
		return (-1);
	return (after_read_all(&data[fd], line));
}
