#include "../../includes/cub3d.h"

void ft_xpm_to_img(t_img *imgtex, t_map *map, t_mlxdata *mlxdata, int pos)
{
	imgtex->img = mlx_xpm_file_to_image(mlxdata->mlx, \
    map->textures[pos], &imgtex->tex_width, &imgtex->tex_width);
    imgtex->addr = NULL;
    imgtex->addr = mlx_get_data_addr(imgtex->img,\
     imgtex->bits, imgtex->line, imgtex->endian);
}