/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:30:00 by llahti            #+#    #+#             */
/*   Updated: 2020/01/24 18:28:07 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_hasnl(char **bufs, char **line, int fd)
{
	char			*temp;
	int				i;

	i = 0;
	while (bufs[fd][i] != '\n')
	{
		if (bufs[fd][i] == '\0')
		{
			temp = ft_strjoin(*line, bufs[fd]);
			free(*line);
			*line = temp;
			return (0);
		}
		i++;
	}
	bufs[fd][i] = '\0';
	temp = ft_strdup(bufs[fd]);
	*line = ft_strjoin_free(*line, temp);
	bufs[fd] = ft_memmove(bufs[fd], &bufs[fd][i + 1], BUFF_SIZE - i);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*bufs[MAX_FD];
	int				red;

	if (!line || fd < 0 || fd > MAX_FD || BUFF_SIZE < 1)
		return (-1);
	if (!bufs[fd])
		bufs[fd] = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(BUFF_SIZE);
	if (ft_hasnl(bufs, line, fd))
		return (1);
	while ((red = read(fd, bufs[fd], BUFF_SIZE)) > 0)
	{
		bufs[fd][red] = '\0';
		if (ft_hasnl(bufs, line, fd))
			break ;
	}
	if (red < 0)
		return (-1);
	if (red == 0)
	{
		if (!bufs[fd][0])
			return (0);
		ft_strdel(&bufs[fd]);
	}
	return (1);
}
