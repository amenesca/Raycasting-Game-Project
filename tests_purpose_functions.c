#include "includes/cub3d.h"
#include <stdio.h>

void print_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}