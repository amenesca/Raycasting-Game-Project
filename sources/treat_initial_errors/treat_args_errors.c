/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_args_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:34:40 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 15:36:04 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	treat_argc(int argc)
{
	if (argc != 2)
	{
		ft_error("cub3d: Error: Wrong number of arguments.");
		return (-1);
	}
	else
		return (0);
}

static int	treat_map(char *map_path)
{
	int	i;

	i = ft_strlen(map_path) - 1;
	while (map_path[i] != '.' && i >= 0)
		i--;
	if (map_path[i])
	{
		if (ft_strcmp(map_path + i, ".cub") == 0)
			return (1);
	}
	ft_error("cub3d: Error: Invalid map extension.");
	return (-1);
}

int	treat_args_error(int argc, char *argv[])
{
	if (treat_argc(argc) == -1)
		return (-1);
	if (treat_map(argv[1]) == -1)
		return (-1);
	return (0);
}
