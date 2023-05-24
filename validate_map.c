#include "includes/cub3d.h"

static char	*ft_strdup_map(const char *s1, t_map *map, int spaces_flag)
{
	int	i;
	char	*map_line;

	map_line = (char *) malloc((map->map_widht + 1) * sizeof(char));
	if (!map_line)
		return (NULL);
	i = -1;

	while (++i < map->map_widht + 1)
		map_line[i] = ' ';
	map_line[i + 1] = '\0';
	if (spaces_flag)
		return ((char *)(map_line));
	i = -1;
	while (++i < (int)ft_strlen(s1))
	{
		map_line[i + 1] = s1[i];
	}
	return ((char *)(map_line));
}

void get_map_widht(t_map *map)
{
	int i;

	i = 1;
	map->map_widht = ft_strlen(map->map[0]); 
	while (map->map[i] != NULL)
	{
		if (ft_strlen(map->map[i]) > (size_t)map->map_widht)
			map->map_widht = ft_strlen(map->map[i]);
		i++;
	}
	map->map_widht += 2;
}

void fill_out_spaces(t_map *map)
{
	int i;

	map->map_height += 2;
	map->remap = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	i = -1;


	map->remap[0] = ft_strdup_map(NULL, map, 1);
	map->remap[map->map_height - 1] = ft_strdup_map(NULL, map, 1);
	while (map->map[++i])
		map->remap[i + 1] = ft_strdup_map(map->map[i], map, 0);
	map->remap[map->map_height] = NULL;
}

int validate_map(t_map *map)
{
	get_map_widht(map);
	fill_out_spaces(map);
	return (0);
}