#include "../../includes/cub3d.h"

int hexToInt(const char *hex) {
    int len = ft_strlen(hex);
    int result = 0;
	int i = 0;

    while (i < len)
	{
        int digitValue = 0;

        if (hex[i] >= '0' && hex[i] <= '9') {
            digitValue = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digitValue = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digitValue = hex[i] - 'a' + 10;
        } else {
            // Caractere inválido encontrado
            printf("Caractere inválido: %c\n", hex[i]);
            return -1;
        }
        result = result * 16 + digitValue;
		i++;
	}

    return result;
}

static int save_colors(char *buff, int i)
{
	char	**splited;
	char	*sub;
	int		j;
	(void)i;

	j = 0;
	splited = ft_split(buff, ' ');
	while (splited[j] != NULL && splited[j][0] != '#')
		j++;
	if (splited[j] == NULL)
		return (-1);
	sub = ft_substr(splited[j], 1, 6);
	printf("%s\n", sub);
	free_array(splited);
	free(sub);
	sub = NULL;
	return (0);
}

static int textures_to_int_arr(t_map *map)
{
	int		i;
	int		fd;
	char	*buff;
	int		int_text[64][64];
//	int		colors[4][20];
	int		init_line;
	
	(void)int_text;
	i = 0;
	buff = malloc(1);
	while (i < 4)
	{
		init_line = 1;
		fd = open(map->textures[i], O_RDONLY);
		while(buff != NULL)
		{
			buff = get_next_line(fd);
			if (init_line < 4)
			{}
			else
			{
				if (save_colors(buff, i) == -1)
				break;
			}
			init_line++;
			free(buff);
		}
		i++;
		close(fd);
	}
	return (0);
}

int read_xpm(t_data *data)
{
	textures_to_int_arr(&data->map);
	return (0);
}