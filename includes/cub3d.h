/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:36 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/04 14:57:00 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# ifdef __linux__
#  include "../mlx_linux/mlx.h"
# else
#  include "../mlx/mlx.h"
# endif

# include "../libft/libft.h"
# include "./defines.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h> // remover depois !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
typedef struct s_map
{
	char		**map;
	char		**remap;
	char		**file_read;
	char		**textures;
	char		**colors;
	int			*ceiling;
	int			*floor;
	int			file_lines;
	int			map_height;
	int			map_width;
} t_map;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits;
	int			line;
	int			endian;
	int			tex_height;
	int			tex_width;
} t_img;

typedef struct s_mlxdata
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits;
	int			line;
	int			finish;
	int			endian;
	t_img		text_N;
	t_img		text_S;
	t_img		text_E;
	t_img		text_W;
} t_mlxdata;

typedef struct s_ray
{
	double		playerpos[2];
	double		dir[2];
	double		move_v;
	double		move_h;
	double		plane[2];
	int			mapX;
	int			mapY;
	int			hit;
	double		stepX;
	double		stepY; //was there a wall hit?
	int			side;
	int			drawEnd;
	int			drawStart;
	int			lineHeight;
	double		rayX;
	double		rayY;
	double		sideX;
	double		sideY;
	double		deltaX;
	double		deltaY;
	double		cameraX;
	double		perp_wall;
	double		oldDirX;
	double		oldPlaneX;
	double		wallX;
	int			texX;
	int			texY;
	double		scale;
	double		texPos;
	int			ceil_color;
	int			floor_color;
	double moveSpeed;
	double rotSpeed;
	double turn;
} t_ray;

typedef struct s_data
{
	t_map		map;
	t_mlxdata	mlxdata;
	t_ray		ray;
} t_data;

// treat_args_error.c
int		treat_args_error(int argc, char *argv[]);

// read_map.c
int		count_lines(char *map_path);
void	remove_endl(t_map *map);
int		read_map(char *map_path, t_map *map);

// get_colors_textures.c
int		get_colors_textures(t_map *map);

// validate_colors_textures.c
int		validate_colors_textures(t_map *map);

// split_textures.c
int		split_textures(t_map *map);

// split_colors.c
int		split_colors(t_map *map);

// test_colors.c
int		test_colors(t_map *map);
int		verify_quant(char ***color);
int		only_numbers(char **color);

//get_map.c
int		get_map(t_map *map);

// get_n_validate.c
int		get_n_validate(t_map *map);

// utils
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup_no_endl(const char *s1);
void	free_array(char **array);
int		count_array(char **array);
int		init_pointers(t_map *map);
void	free_all(t_map *map);
int		ft_error(char *s);

// validate_map.c
int		validate_map(t_map *map);

//init_mlx.c
int		init_data(t_data *data);
int		init_mlx(t_data *data);
void	ft_xpm_to_img(t_img *imgtex, t_map *map, t_mlxdata *mlxdata, int pos);
int		key_hook(int keycode, t_mlxdata *game);
int		close_game(t_mlxdata *game);
void	ft_xpm_to_img(t_img *imgtex, t_map *map, t_mlxdata *mlxdata, int pos);

//deal_key
int	deal_key(int keycode, t_data *data);
int	undeal_key(int keycode, t_data *data);

//movement
void	movement_y(t_data *data);
void	movement_x(t_data *data);
void	mov_camera(t_data *data);

//free_functions
void	free_basic(t_map *map);
void	free_text_col(t_map *map);
void	free_text_col_array(t_map *map);
void	free_ceil_floor(t_map *map);

//raycasting
int		get_info(t_data *data);
void	get_hex_colors(t_data *data);
void	put_ceil_floor(t_data *data);
int		divideColorByValue(int color, int value);
int		game(t_data *data);
void	raycaster(t_data *data);
int		handle_keys(int keycode, t_data *data);
void	verline(t_data *data, int x, int start, int end, int color);
void    ft_mlx_pixel_put(t_data *data, int x, int y, int pixel);

// ****** Funcoes para testar coisas ****** apagar depois

void	print_array(char **array);

#endif
