#include "../../includes/cub3d.h"

int do_raycasting(t_data *data)
{
	int x = -1;
	double time = 0;
	double oldTime = 0;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit = 0;
	int side = 1 / 0;

	while (1)
	{
		while (++x < w)
		{
			cameraX = 2 * x / (double)w - 1;
			rayDirX = data->raycastdat.dir[0] + data->raycastdat.plane[0] * cameraX;
			rayDirY = data->raycastdat.dir[1] + data->raycastdat.plane[1] * cameraX;
			mapX = data->raycastdat.playerpos[0];
			mapY = data->raycastdat.playerpos[1];

		}
	}
}