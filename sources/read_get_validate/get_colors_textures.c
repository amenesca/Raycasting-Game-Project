/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:37:27 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 13:44:58 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_no_so(t_map *map, int i)
{
	if (ft_strnstr(map->file_read[i], "NO ", \
	ft_strlen(map->file_read[i])) != NULL)
	{
		if (map->textures[NO] == NULL)
			map->textures[NO] = ft_strdup(map->file_read[i]);
		else
			return (-1);
	}
	if (ft_strnstr(map->file_read[i], "SO ", \
	ft_strlen(map->file_read[i])) != NULL)
	{
		if (map->textures[SO] == NULL)
			map->textures[SO] = ft_strdup(map->file_read[i]);
		else
			return (-1);
	}
	return (0);
}

int	get_we_ea(t_map *map, int i)
{
	if (ft_strnstr(map->file_read[i], "WE ", \
	ft_strlen(map->file_read[i])) != NULL)
	{
		if (map->textures[WE] == NULL)
			map->textures[WE] = ft_strdup(map->file_read[i]);
		else
			return (-1);
	}
	if (ft_strnstr(map->file_read[i], "EA ", \
	ft_strlen(map->file_read[i])) != NULL)
	{
		if (map->textures[EA] == NULL)
			map->textures[EA] = ft_strdup(map->file_read[i]);
		else
			return (-1);
	}
	return (0);
}

static int	get_textures(t_map *map)
{
	int	i;

	i = -1;
	while (map->file_read[++i] != NULL)
	{
		if (get_no_so(map, i) != 0)
			return (-1);
		if (get_we_ea(map, i) != 0)
			return (-1);
	}
	map->textures[4] = NULL;
	return (0);
}

static int	get_colors(t_map *map)
{
	int	i;

	i = -1;
	while (map->file_read[++i] != NULL)
	{
		if (ft_strnstr(map->file_read[i], "F ", \
		ft_strlen(map->file_read[i])) != NULL)
		{
			if (map->colors[0] == NULL)
				map->colors[0] = ft_strdup(map->file_read[i]);
			else
				return (-1);
		}
		else if (ft_strnstr(map->file_read[i], "C ", \
		ft_strlen(map->file_read[i])) != NULL)
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

int	get_colors_textures(t_map *map)
{
	if (get_textures(map) == -1)
	{
		free_text_col_array(map);
		return (write(2, "cub3d: Error: Wrong textures.\n", 30));
	}
	if (get_colors(map) == -1)
	{
		free_text_col_array(map);
		return (write(2, "cub3d: Error: Wrong colors.\n", 28));
	}
	return (0);
}
