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

void remove_endl(t_map *map, int lines)
{
	int i;
	char **map_read;

	i = 0;
	map_read = (char **)malloc(sizeof(char *) * (lines + 1));
	while (i < lines)
	{
		map_read[i] = ft_strdup_no_endl(map->map_read[i]);
		i++;
	}
	map_read[i] = NULL;
	free_array(map->map_read);
	map->map_read = map_read;
}

void get_textures_path(t_map *map)
{
	int i;

	i = -1;
	while (map->map_read[++i] != NULL)
	{
		if (ft_strncmp(map->map_read[i], "NO", 2) == 0)
			map->textures[0] = ft_strdup(map->map_read[i]);
		else if (ft_strncmp(map->map_read[i], "SO", 2) == 0)
			map->textures[1] = ft_strdup(map->map_read[i]);
		else if (ft_strncmp(map->map_read[i], "WE", 2) == 0)
			map->textures[2] = ft_strdup(map->map_read[i]);
		else if (ft_strncmp(map->map_read[i], "EA", 2) == 0)
			map->textures[3] = ft_strdup(map->map_read[i]);
	}
	map->textures[4] = NULL;
}

void get_colors(t_map *map)
{
	int i;

	i = -1;
	while (map->map_read[++i] != NULL)
	{
		if (ft_strncmp(map->map_read[i], "F ", 2) == 0)
			map->colors[0] = ft_strdup(map->map_read[i]);
		else if (ft_strncmp(map->map_read[i], "C ", 2) == 0)
			map->colors[1] = ft_strdup(map->map_read[i]);
	}
	map->colors[2] = NULL;
}

void read_map(char *map_path, t_map *map)
{
	int lines;
	int i;
	int fd;

	i = 0;
	fd = open(map_path, O_RDONLY);
	lines = count_lines(map_path);
	map->map_read = (char **)malloc(sizeof(char *) * (lines + 1));
	while (i < lines)
	{
		map->map_read[i] = get_next_line(fd);
		i++;
	}
	map->map_read[i] = NULL;
	close(fd);
	remove_endl(map, lines);
	get_textures_path(map);
	get_colors(map);
}
