#include "includes/cub3d.h"

int test_values(int *colors)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (colors[i] < 0 || colors[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

int only_numbers(char **color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (color[i][j])
		{
			if (!ft_isdigit(color[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int validate_ceiling(t_map *map)
{
	int i;
	char **color;

	color = ft_split(map->colors[1], ',');
	if (count_array(color) != 3)
		return (1);
	if (only_numbers(color) > 0)
		return (1);
	map->ceiling = (int *)malloc(sizeof(int) * 3);
	i = 0;
	while (i < 3)
	{
		map->ceiling[i] = ft_atoi(color[i]);
		i++;
	}	
	if (test_values(map->ceiling) > 0)
		return (1);
	return (0);
}

int validate_floor(t_map *map)
{
	int i;
	char **color;

	color = ft_split(map->colors[0], ',');
	if (count_array(color) != 3)
		return (1);
	if (only_numbers(color) > 0)
		return (1);
	map->floor = (int *)malloc(sizeof(int) * 3);
	i = 0;
	while (i < 3)
	{
		map->floor[i] = ft_atoi(color[i]);
		i++;
	}
	if (test_values(map->floor) > 0)
		return (1);
	return (0);
}

int test_colors(t_map *map)
{
	if (validate_ceiling(map) > 0)
	{
		write(2, "cub3d: Error: Wrong colors\n", 28);
		return (1);
	}
	if (validate_floor(map) > 0)
	{
		write(2, "cub3d: Error: Wrong colors\n", 28);
		return (1);
	}
	return (0);
}