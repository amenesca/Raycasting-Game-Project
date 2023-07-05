/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:55:28 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 13:57:02 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	test_values(int *colors)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (colors[i] < 0 || colors[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

int	only_numbers(char **color)
{
	int	i;
	int	j;

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

static int	validate_ceiling(t_map *map)
{
	int		i;
	char	**color;

	color = ft_split(map->colors[1], ',');
	if (verify_quant(&color) > 0)
		return (1);
	map->ceiling = (int *)ft_calloc(sizeof(int), 3);
	i = 0;
	while (i < 3)
	{
		map->ceiling[i] = ft_atoi(color[i]);
		i++;
	}
	if (test_values(map->ceiling) > 0)
	{
		free_array(color);
		return (1);
	}
	free_array(color);
	return (0);
}

static int	validate_floor(t_map *map)
{
	int		i;
	char	**color;

	color = ft_split(map->colors[0], ',');
	if (verify_quant(&color) != 0)
		return (1);
	map->floor = (int *)ft_calloc(sizeof(int), 3);
	i = 0;
	while (i < 3)
	{
		map->floor[i] = ft_atoi(color[i]);
		i++;
	}
	if (test_values(map->floor) > 0)
	{
		free_array(color);
		return (1);
	}
	free_array(color);
	return (0);
}

int	test_colors(t_map *map)
{
	map->ceiling = NULL;
	map->floor = NULL;
	if (validate_ceiling(map) > 0)
	{
		free_text_col_array(map);
		free_ceil_floor(map);
		ft_error("cub3d: Error: Wrong colors");
		return (1);
	}
	if (validate_floor(map) > 0)
	{
		free_text_col_array(map);
		free_ceil_floor(map);
		ft_error("cub3d: Error: Wrong colors");
		return (1);
	}
	return (0);
}
