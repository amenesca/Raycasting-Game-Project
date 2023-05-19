#include "cub3d.h"
#include <stdio.h>


int	count_lines(char *map_path)
{
	int	i;
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cub3d: Error: invalid fd\n", 25);
		return (-1);
	}
	i = 0;
	while (get_next_line(fd) != 0)
		i++;
	printf("i = %i\n", i);
	close(fd);
	return (i);
}