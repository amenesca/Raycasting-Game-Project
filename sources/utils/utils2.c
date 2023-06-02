#include "../../includes/cub3d.h"

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
	if (map->remap)
		free_array(map->remap);
}