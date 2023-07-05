/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:48:20 by amenesca          #+#    #+#             */
/*   Updated: 2022/06/20 11:27:30 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_to_buff(int fd, char *join)
{
	char	*buff;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!my_strchr(join, '\n') && bytes)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		if (!join)
		{
			join = malloc(1 * sizeof(char));
			*join = '\0';
		}
		join = my_strjoin(join, buff);
	}
	free(buff);
	return (join);
}

static char	*strdupline(char *join)
{
	size_t	i;
	char	*s;

	i = 0;
	if (!join[i])
		return (NULL);
	while (join[i] && join[i] != '\n')
		i++;
	s = malloc((i + 2) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (join[i] && join[i] != '\n')
	{
		s[i] = join[i];
		i++;
	}
	if (join[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

static char	*set_join(char *join)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = size_of_line(join);
	if (!join[i])
	{
		free (join);
		return (NULL);
	}
	s = malloc((my_strlen(join) - i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (join[i])
		s[j++] = join[i++];
	s[j] = '\0';
	free(join);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*join[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	join[fd] = read_to_buff(fd, join[fd]);
	if (!join[fd])
		return (NULL);
	line = strdupline(join[fd]);
	join[fd] = set_join(join[fd]);
	return (line);
}
