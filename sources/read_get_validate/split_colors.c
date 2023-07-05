/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:53:13 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 13:53:52 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_colors(char *line)
{
	if (ft_strcmp(line, "C") == 0 \
	|| ft_strcmp(line, "F") == 0)
	{
		return (1);
	}
	return (0);
}

static int	validate_colors(char **color)
{
	if (is_colors(color[0]) && count_array(color) == 2)
		return (0);
	return (1);
}

int	split_colors(t_map *map)
{
	int		i;
	int		error_flag;
	char	**splited;

	i = 0;
	error_flag = 0;
	while (map->colors[i] != NULL && !error_flag)
	{
		splited = ft_split(map->colors[i], ' ');
		if (validate_colors(splited) > 0)
			error_flag = 1;
		if (error_flag == 0)
		{
			free(map->colors[i]);
			map->colors[i] = ft_strdup(splited[1]);
		}
		free_array(splited);
		i++;
	}
	if (error_flag == 1)
		return (1);
	return (0);
}
