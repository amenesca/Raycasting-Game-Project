/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:42 by amenesca          #+#    #+#             */
/*   Updated: 2023/05/23 16:00:22 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	validate_elements(t_map *map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (map->textures[i] == NULL)
			return (write(2, "cub3d: Error: Wrong textures\n", 29));
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (map->colors[i] == NULL)
			return (write(2, "cub3d: Error: Wrong colors\n", 27));
		i++;
	}
	return (0);
}

int	init_pointers(t_map *map)
{
	int	i;

	i = 0;
	map->textures = (char **)ft_calloc(sizeof(char *), 5);
	if (map->textures == NULL)
		return (-1);
	while (i < 5)
		map->textures[i++] = NULL;
	map->colors = (char **)ft_calloc(sizeof(char *), 3);
	if (map->colors == NULL)
		return (-1);
	while (i < 3)
		map->colors[i++] = NULL;
	return (0);
}

int main(int argc, char *argv[]) 
{
	t_map map;

	if (treat_argc(argc) == -1)
		return (-1);
	if (treat_map(argv[1]) == -1)
		return (-1);
	read_map(argv[1], &map);
	if (map.file_read == NULL)
		return (-1);
	print_array(map.file_read);
	
//	write(1, "\n\n\n", 3);
	
	print_array(map.textures);
	print_array(map.colors);
	print_array(map.map);
	
	free_array(map.file_read);
	free_array(map.textures);
	free_array(map.colors);
	free_array(map.map);
	return (0);
}
