/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-bou <hben-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:47:42 by hben-bou          #+#    #+#             */
/*   Updated: 2022/12/16 04:58:48 by hben-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*ptr;

	i = 0;
	k = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[k])
		ptr[i++] = s2[k++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_outline(char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s || !s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	ptr = (char *)malloc(sizeof(char) * i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_next_line(char *s)
{
	int		i;
	int		k;
	char	*ptr;

	i = 0;
	k = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s || !s[i])
	{
		free(s);
		return (NULL);
	}
	ptr = (char *)malloc(sizeof(char) * ft_strlen(s) - i + 1);
	if (!ptr)
		return (NULL);
	i++;
	while (s[i])
		ptr[k++] = s[i++];
	ptr[k] = '\0';
	free(s);
	return (ptr);
}
