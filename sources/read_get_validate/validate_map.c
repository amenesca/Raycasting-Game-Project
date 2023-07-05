/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:58:24 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 14:01:05 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	space_condition(t_map *map, int i, int j)
{
	if (map->remap[i][j - 1] != ' ' && map->remap[i][j - 1] != '1')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i][j + 1] != ' ' && map->remap[i][j + 1] != '1')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i - 1][j] != ' ' && map->remap[i - 1][j] != '1')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i + 1][j] != ' ' && map->remap[i + 1][j] != '1')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i - 1][j - 1] != ' ' && map->remap[i - 1][j - 1] != '1')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i - 1][j + 1] != ' ' && map->remap[i - 1][j + 1] != '1')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i + 1][j - 1] != ' ' && map->remap[i + 1][j - 1] != '1')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i + 1][j + 1] != ' ' && map->remap[i + 1][j + 1] != '1')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	return (0);
}

static int	char_condition(t_map *map, int i, int j)
{
	if (map->remap[i][j - 1] == ' ')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i][j + 1] == ' ')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i - 1][j] == ' ')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i + 1][j] == ' ')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i - 1][j - 1] == ' ')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i - 1][j + 1] == ' ')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i + 1][j - 1] == ' ')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	if (map->remap[i + 1][j + 1] == ' ')
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	return (0);
}

int	validate_space(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->map_height - 1)
	{
		j = 1;
		while (j < map->map_width - 1)
		{
			if (map->remap[i][j] == ' ')
			{
				if (space_condition(map, i, j) != 0)
					return (1);
			}
			if (is_valid_char(map->remap[i][j]) == 2)
			{
				if (char_condition(map, i, j) != 0)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_map(t_map *map)
{
	get_map_width(map);
	fill_out_spaces(map);
	if (validade_char(map))
	{
		free_all(map);
		return (1);
	}
	if (validate_space(map))
	{
		free_all(map);
		return (1);
	}
	return (0);
}
