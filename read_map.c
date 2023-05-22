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

void remove_endl(char **map_read)
{
	int i;

	i = -1;

	while(map_read[++i])
		map_read[i] = free_strtrim(map_read[i], "\n");
}

void read_map(char *map_path, t_map *map)
{
	int lines;
	int i;
	int fd;

	i = 0;
	fd = open(map_path, O_RDONLY);
	lines = count_lines(map_path);
	map->map_read = (char **)malloc(sizeof(char *) * lines + 1);
	while (i < lines)
	{
		map->map_read[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	remove_endl(map->map_read);
}