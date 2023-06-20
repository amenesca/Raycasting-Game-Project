/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:39:38 by amenesca          #+#    #+#             */
/*   Updated: 2023/06/19 18:09:53 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_lines(char *map_path)
{
	int	i;
	int	fd;
	char *buff;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_error("Cub3d: Error: invalid fd");
		return (-1);
	}
	i = 0;
	while (1)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			break ;
		free(buff);
		i++;
	}
	close(fd);
	return (i);
}

void remove_endl(t_map *map)
{
	int i;
	char **map_read;

	i = 0;
	map_read = (char **)ft_calloc( (map->file_lines + 2), sizeof(char *));
	while (i < map->file_lines)
	{
		map_read[i] = ft_strdup_no_endl(map->file_read[i]);
		i++;
	}
	map_read[i] = NULL;
	free_array(map->file_read);
	map->file_read = map_read;
}

int	read_map(char *map_path, t_map *map)
{
	int i;
	int fd;

	i = 0;
	fd = open(map_path, O_RDONLY);
	map->file_lines = count_lines(map_path);
	if (map->file_lines == -1)
	{
		free_text_col(map);
		return (1);
	}
	if (map->file_lines == 0)
	{
		free_text_col(map);
		ft_error("cub3d: Error: Empty file");
		return (1);
	}
	map->file_read = (char **)ft_calloc(sizeof(char *),\
 (map->file_lines + 2));
	while (i < map->file_lines)
	{
		map->file_read[i] = get_next_line(fd);
		i++;
	}
	map->file_read[i] = NULL;
	close(fd);
	remove_endl(map);
	return (0);
}
