/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:52:15 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 11:53:12 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_basic(t_map *map)
{
	free_array(map->textures);
	free_array(map->colors);
	free_array(map->file_read);
	return ;
}

void	free_text_col(t_map *map)
{
	free(map->textures);
	free(map->colors);
	return ;
}

void	free_ceil_floor(t_map *map)
{
	if (map->floor)
		free(map->floor);
	if (map->ceiling)
		free(map->ceiling);
}

void	free_text_col_array(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i < 2)
		{
			if ((map->colors[i]) != NULL)
				free(map->colors[i]);
			map->colors[i] = NULL;
		}
		if (map->textures != NULL)
			free(map->textures[i]);
		map->textures[i] = NULL;
		i++;
	}
	free(map->textures);
	map->textures = NULL;
	free(map->colors);
	map->colors = NULL;
	free_array(map->file_read);
}
