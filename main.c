/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:42 by amenesca          #+#    #+#             */
/*   Updated: 2023/05/23 20:03:12 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	validate_elements(t_map *map)
{
	int i;
	int fd;

	i = -1;
	if (split_textures(map) > 0)
		return (write(2, "cub3d: Error: Wrong textures\n", 29));
	if (split_colors(map) > 0)
		return (write(2, "cub3d: Error: Wrong colors\n", 27));
	while (++i < 4)
	{
		if (map->textures[i] == NULL)
			return (write(2, "cub3d: Error: Wrong textures\n", 29));
		fd = open(map->textures[i], O_RDWR);
		if (fd == -1)
			return (write(2, "cub3d: Error: Textures path invalid\n", 37));
		close(fd);
	}
	i = 0;
	while (i < 2)
	{
		if (map->colors[i++] == NULL)
			return (write(2, "cub3d: Error: Wrong colors\n", 27));
	}
	return (0);
}

int	init_pointers(t_map *map)
{
	int	i;

	i = 0;
	map->map = NULL;
	map->file_read = NULL;
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

void free_all(t_map *map)
{
	if (map->file_read)
		free_array(map->file_read);
	if (map->textures)
		free_array(map->textures);
	if (map->colors)
		free_array(map->colors);
	if (map->map)
		free_array(map->map);
}

int main(int argc, char *argv[]) 
{
	t_map map;

	if (treat_argc(argc) == -1)
		return (-1);
	if (treat_map(argv[1]) == -1)
		return (-1);
	init_pointers(&map);
	read_map(argv[1], &map);
	if (map.file_read == NULL)
	{
		free_all(&map);
		return (-1);
	}
	print_array(map.file_read);
	
	print_array(map.textures);
	print_array(map.colors);
	print_array(map.map);

	free_all(&map);
	return (0);
}

/*HEAP SUMMARY:
==19154==     in use at exit: 1,404,803 bytes in 814 blocks
==19154==   total heap usage: 1,007 allocs, 193 frees, 2,590,568 bytes allocated
==19154== 
==19154== LEAK SUMMARY:
==19154==    definitely lost: 10,793 bytes in 225 blocks
==19154==    indirectly lost: 5,664 bytes in 130 blocks
==19154==      possibly lost: 472 bytes in 10 blocks
==19154==    still reachable: 11,272 bytes in 60 blocks
==19154==         suppressed: 1,376,602 bytes in 389 blocks*/