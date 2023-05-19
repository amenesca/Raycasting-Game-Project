#include "includes/cub3d.h"
#include <stdio.h>

void print_map(char **map_read)
{
	int i = 0;

	while (map_read[i])
	{
		printf("%s\n", map_read[i]);
		i++;
	}
}