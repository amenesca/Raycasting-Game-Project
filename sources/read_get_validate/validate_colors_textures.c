#include "../.././includes/cub3d.h"

int	validate_colors_textures(t_map *map)
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