/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:39:38 by amenesca          #+#    #+#             */
/*   Updated: 2023/05/24 18:29:59 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(char *map_path)
{
	int	i;
	int	fd;
	char *buff;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cub3d: Error: invalid fd\n", 25);
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
	map_read = (char **)ft_calloc( (map->file_lines + 1), sizeof(char *));
	while (i < map->file_lines)
	{
		map_read[i] = ft_strdup_no_endl(map->file_read[i]);
		i++;
	}
	map_read[i] = NULL;
	free_array(map->file_read);
	map->file_read = map_read;
}

int	 get_textures(t_map *map)
{
	int i;

	i = -1;
	while (map->file_read[++i] != NULL)
	{
		if (ft_strnstr(map->file_read[i], "NO ", ft_strlen(map->file_read[i])) != NULL)
		{
			if (map->textures[NO] == NULL)
				map->textures[NO] = ft_strdup(map->file_read[i]);
			else
				return (-1);
		}
		else if (ft_strnstr(map->file_read[i], "SO ", ft_strlen(map->file_read[i])) != NULL)
		{
			if (map->textures[SO] == NULL)
				map->textures[SO] = ft_strdup(map->file_read[i]);
			else
				return (-1);
		}
		else if (ft_strnstr(map->file_read[i], "WE ", ft_strlen(map->file_read[i])) != NULL)
		{
			if (map->textures[WE] == NULL)
				map->textures[WE] = ft_strdup(map->file_read[i]);
			else
				return (-1);
		}
		else if (ft_strnstr(map->file_read[i], "EA ", ft_strlen(map->file_read[i])) != NULL)
		{
			if (map->textures[EA] == NULL)
				map->textures[EA] = ft_strdup(map->file_read[i]);
			else
				return (-1);
		}
	}
	map->textures[4] = NULL;
	return (0);
}

int	get_colors(t_map *map)
{
	int i;

	i = -1;
	while (map->file_read[++i] != NULL)
	{
		if (ft_strnstr(map->file_read[i], "F ", ft_strlen(map->file_read[i])) != NULL)
		{
			if (map->colors[0] == NULL)
				map->colors[0] = ft_strdup(map->file_read[i]);
			else
				return (-1);

		}
		else if (ft_strnstr(map->file_read[i], "C ", ft_strlen(map->file_read[i])) != NULL)
		{
			if (map->colors[1] == NULL)
				map->colors[1] = ft_strdup(map->file_read[i]);
			else
				return (-1);
		}
	}
	map->colors[2] = NULL;
	return (0);
}


static int is_element(char *line)
{
	if (ft_strnstr(line, "NO ",  ft_strlen(line)) != NULL\
	 || ft_strnstr(line, "SO ", ft_strlen(line)) != NULL\
	|| ft_strnstr(line, "WE ", ft_strlen(line)) != NULL\
	 || ft_strnstr(line, "EA ", ft_strlen(line)) != NULL\
	|| ft_strnstr(line, "F ", ft_strlen(line)) != NULL\
	 || ft_strnstr(line, "C ", ft_strlen(line)) != NULL)
	{
		return (1);
	}
	return (0);
}

void get_map(t_map *map)
{
	int i;
	int flag;
	int j;

	i = 0;
	flag = 0;
	while(map->file_read[i])
	{
		if (is_element(map->file_read[i]))
			flag++;
		i++;
		if (flag == 6)
		{
			while (map->file_read[i][0] == '\0' && map->file_read[i] != NULL)
				i++;
			break;
		}
	}
	map->map_height = map->file_lines - i;
	map->map = (char **)ft_calloc(sizeof(char *), (map->map_height + 1));
	j = 0;
	while (j < map->map_height)
		map->map[j++] = ft_strdup(map->file_read[i++]);
	map->map[j] = NULL;
}

int	read_map(char *map_path, t_map *map)
{
	int i;
	int fd;

	i = 0;
	fd = open(map_path, O_RDONLY);
	map->file_lines = count_lines(map_path);
	if (map->file_lines == 0)
	{
		write(2, "cub3d: Error: Empty file\n", 26);
		return (1);
	}
	map->file_read = (char **)ft_calloc(sizeof(char *),\
 (map->file_lines + 1));
	while (i < map->file_lines)
	{
		map->file_read[i] = get_next_line(fd);
		i++;
	}
	map->file_read[i] = NULL;
	close(fd);
	remove_endl(map);
	init_pointers(map);
	if (get_textures(map) == -1)
		return (write(2, "cub3d: Error: Wrong textures\n", 29));
	if (get_colors(map) == -1)
		return (write(2, "cub3d: Error: Wrong colors\n", 27));
	if (validate_elements(map) > 0)
		return (1);
	if (test_colors(map) > 0)
		return (1);
	get_map(map);
	validate_map(map);
	return (0);
}
