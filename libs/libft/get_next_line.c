/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:04:01 by femarque          #+#    #+#             */
/*   Updated: 2023/07/06 16:04:06 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	i = 0;
	rd = 0;
	buffer = malloc(100000);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
		if (rd <= 0)
			break ;
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}
