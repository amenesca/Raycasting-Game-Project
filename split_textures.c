#include "./includes/cub3d.h"

static int count_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

static int is_textures(char *line)
{
	if (ft_strcmp(line, "NO") == 0\
 || ft_strcmp(line, "SO") == 0\
 || ft_strcmp(line, "WE") == 0\
 || ft_strcmp(line, "EA") == 0)
	{
		return (1);
	}
	return (0);
}

int validate_textures(char **texture)
{
	if (is_textures(texture[0]) && count_array(texture) == 2)
		return (0);
	return (1);
}

int split_textures(t_map *map)
{
	int i;
	int error_flag;
	char **splited;

	i = 0;
	error_flag = 0;
	while (map->textures[i] != NULL && !error_flag)
	{
		splited = ft_split(map->textures[i], ' ');
		if (validate_textures(splited) > 0)
			error_flag = 1;
		if (error_flag == 0)
		{
			free(map->textures[i]);
			map->textures[i] = ft_strdup(splited[1]);
		}
		free_array(splited);
		i++;
	}
	if (error_flag == 1)
		return (1);
	return (0);
}
