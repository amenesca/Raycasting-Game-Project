/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:57:20 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 13:58:13 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.././includes/cub3d.h"

static int	treat_free_errors(int error, t_map *map)
{
	if (error == 1)
	{
		free_text_col_array(map);
		return (write(2, "cub3d: Error: Wrong textures\n", 29));
	}
	else if (error == 2)
	{
		free_text_col_array(map);
		return (write(2, "cub3d: Error: Wrong colors\n", 27));
	}
	else
		return (0);
}

static int	check_textures_path(t_map *map)
{
	int	i;
	int	error;
	int	fd;

	error = 0;
	i = -1;
	fd = -1;
	while (++i < 4)
	{
		if (map->textures[i] == NULL)
			error = 1;
		else
			fd = open(map->textures[i], O_RDWR);
		if (fd == -1)
		{
			error = 1;
			break ;
		}
		close(fd);
	}
	return (error);
}

int	validate_colors_textures(t_map *map)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	if (split_textures(map) > 0)
		error = 1;
	if (split_colors(map) > 0)
		error = 2;
	error = check_textures_path(map);
	while (i < 2)
	{
		if (map->colors[i++] == NULL)
			error = 2;
	}
	return (treat_free_errors(error, map));
}
