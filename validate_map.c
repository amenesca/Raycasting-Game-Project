/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:21:16 by maragao           #+#    #+#             */
/*   Updated: 2023/05/24 18:50:16 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static char	*ft_strdup_map(const char *s1, t_map *map, int spaces_flag)
{
	int	i;
	char	*map_line;

	map_line = (char *) malloc((map->map_widht + 1) * sizeof(char));
	if (!map_line)
		return (NULL);
	i = -1;

	while (++i < map->map_widht + 1)
		map_line[i] = ' ';
	map_line[i + 1] = '\0';
	if (spaces_flag)
		return ((char *)(map_line));
	i = -1;
	while (++i < (int)ft_strlen(s1))
	{
		map_line[i + 1] = s1[i];
	}
	return ((char *)(map_line));
}

void get_map_widht(t_map *map)
{
	int i;

	i = 1;
	map->map_widht = ft_strlen(map->map[0]); 
	while (map->map[i] != NULL)
	{
		if (ft_strlen(map->map[i]) > (size_t)map->map_widht)
			map->map_widht = ft_strlen(map->map[i]);
		i++;
	}
	map->map_widht += 2;
}

void fill_out_spaces(t_map *map)
{
	int i;

	map->map_height += 2;
	map->remap = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	i = -1;


	map->remap[0] = ft_strdup_map(NULL, map, 1);
	map->remap[map->map_height - 1] = ft_strdup_map(NULL, map, 1);
	while (map->map[++i])
		map->remap[i + 1] = ft_strdup_map(map->map[i], map, 0);
	map->remap[map->map_height] = NULL;
}

static int	is_valid_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	else if (c != '0' && c != '1' && c != ' ')
		return (1);
	return (0);
}

int	validade_char(t_map *map)
{
	int	flag_error;
	int	i;
	int	j;

	flag_error = 0;
	i = 1;
	while (i < map->map_height - 1)
	{
		j = 1;
		while (j < map->map_widht - 1)
		{
			if (is_valid_char(map->remap[i][j]) == 2 && flag_error == 0)
				flag_error = 1;
			else if (is_valid_char(map->remap[i][j]) == 2 && flag_error == 1)
				return (write(2, "cub3d: Error: Invalid map\n", 26));
			else if (is_valid_char(map->remap[i][j]) == 1)
				return (write(2, "cub3d: Error: Invalid map\n", 26));
			j++;
		}
		i++;
	}
	if (flag_error != 1)
		return (write(2, "cub3d: Error: Invalid map\n", 26));
	return (0);
}

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

int	validate_space(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->map_height - 1)
	{
		j = 1;
		while (j < map->map_widht - 1)
		{
			if (map->remap[i][j] == ' ')
			{
				if (space_condition(map, i, j) != 0)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int validate_map(t_map *map)
{
	get_map_widht(map);
	fill_out_spaces(map);
	if (validade_char(map))
		return (1);
	if (validate_space(map))
		return (1);
	return (0);
}
