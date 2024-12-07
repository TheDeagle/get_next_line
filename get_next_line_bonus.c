/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:50:03 by hben-bou          #+#    #+#             */
/*   Updated: 2022/12/16 06:53:06 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_str(int fd, char *s)
{
	int		read_bytes;
	char	*ptr;

	read_bytes = 1;
	ptr = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	while (read_bytes != 0)
	{
		read_bytes = read(fd, ptr, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(ptr);
			free(s);
			return (NULL);
		}
		ptr[read_bytes] = '\0';
		s = ft_strjoin(s, ptr);
		if (ft_strchr(s, '\n'))
			break ;
	}
	free(ptr);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line[4096];

	if (fd < 0 || 0 >= BUFFER_SIZE)
		return (NULL);
	next_line[fd] = ft_read_str(fd, next_line[fd]);
	if (!next_line[fd])
		return (NULL);
	line = ft_outline(next_line[fd]);
	next_line[fd] = ft_next_line(next_line[fd]);
	return (line);
}
