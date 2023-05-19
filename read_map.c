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

char **read_map(char *map_path)
{
	int lines;
	char **map_read;
	int i;
	int fd;

	i = 0;
	fd = open(map_path, O_RDONLY);
	lines = count_lines(map_path);
	map_read = (char **)malloc(sizeof(char *) * lines + 1);
	while (i < lines)
	{
		map_read[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map_read);
}