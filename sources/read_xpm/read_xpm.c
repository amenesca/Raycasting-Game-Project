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

static int save_colors(char *buff, int ***colors, int i)
{
	char **splited;

	splited = ft_split(buff, ' ');

}

static int textures_to_int_arr(t_map *map)
{
	int		i;
	int		fd;
	char	*buff;
	int		int_text[64][64];
	int		colors[4][20];
	int		cond;
	int		init_line;
	
	i = 0;
	buff = NULL;
	cond = 1;
	init_line = 0;
	while (i < 4)
	{
		fd = open(map->textures[i], O_RDONLY);
		while(cond != 0 || buff != NULL)
		{
			cond = 1;
			buff = get_next_line(fd);
			if (init_line < 4)
				free(buff);
			else
			{
				save_colors(buff, &colors, i);
				free(buff);
			}
			init_line++;
		}
		i++;
	}
}

int read_xpm(t_data *data)
{
	textures_to_int_arr(&data->map.textures);
}