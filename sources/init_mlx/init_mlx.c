#include "../../includes/cub3d.h"

int init_mlx(t_mlxdata *mlxdata)
{
	mlxdata->mlx = mlx_init();
	mlxdata->mlx_win = mlx_new_window(mlxdata->mlx, w, h, "cub3d");
	return (0);
}