/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:47:29 by hben-bou          #+#    #+#             */
/*   Updated: 2022/12/16 09:20:23 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*next_line;

	if (fd < 0 || 0 >= BUFFER_SIZE)
		return (NULL);
	next_line = ft_read_str(fd, next_line);
	if (!next_line)
		return (NULL);
	line = ft_outline(next_line);
	next_line = ft_next_line(next_line);
	return (line);
}

/*int main()
{
	int i = 0;
	int fd = open("test.txt", O_RDWR);
	char *str;

	while (i < 3)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
}*/