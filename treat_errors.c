#include "includes/cub3d.h"

int treat_argc(int argc)
{
	if (argc != 2)
	{
		write(2, "cub3d: Error: Wrong number of arguments.\n", 42);
		return (-1);
	}
	else
		return (0);
}

int	treat_map(char *map_path)
{
	int i;

	i = ft_strlen(map_path) - 1;
	while (map_path[i] != '.' && i >= 0)
		i--;
	if (map_path[i])
	{
		if (ft_strcmp(map_path + i, ".cub") == 0)
			return (1);
	}
	write(2, "cub3d: Error: Invalid map extension", 35);
	return (-1);
}