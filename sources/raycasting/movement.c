/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:44:18 by femarque          #+#    #+#             */
/*   Updated: 2023/06/30 14:56:39 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//===BASEADO NO LODEV, MAS SEPARADO EM FUNÇÕES MENORES E COM AJUDA DO FABRÍCIO===

void	movement_y(t_map *map, t_ray *ray)
{
	if (map->map[(int)(ray->playerpos[0] + ray->walk_y * \
	(ray->dir[0] * ray->speed))][(int)ray->playerpos[1]] == '0')
		ray->playerpos[0] += ray->walk_y * (ray->dir[0] * ray->speed);
	if (map->map[(int)(ray->playerpos[0])][(int)(ray->playerpos[1] + ray->walk_y * \
	(ray->dir[0] * ray->speed))] == '0')
		ray->playerpos[1] += ray->walk_y * (ray->dir[1]* ray->speed);
}

void	movement_x(t_map *map, t_ray *ray)
{
	if (map->map[(int)(ray->playerpos[0] + ray->walk_x * \
		(ray->plane[0] * ray->speed))][(int)ray->playerpos[1]] == '0')
		ray->playerpos[0] += ray->walk_x * (ray->plane[0] * ray->speed);
	if (map->map[(int)ray->playerpos[0]][(int)(ray->playerpos[1] + ray->walk_x * \
		(ray->plane[1] * ray->speed))] == '0')
		ray->playerpos[1] += ray->walk_x * (ray->plane[1] * ray->speed);
}

void	mov_camera(t_ray *ray)
{
	ray->rotation = ray->turn * ray->speed;
	ray->old_dir = ray->dir[0];
	ray->dir[0] = ray->dir[0] * cos(ray->rotation) - ray->dir[1] * sin(ray->rotation);
	ray->dir[1] = ray->old_dir * sin(ray->rotation) + ray->dir[1] * cos(ray->rotation);
	ray->old_plane = ray->plane[0];
	ray->plane[0] = ray->plane[0] * cos(ray->rotation) - ray->plane[1] * sin(ray->rotation);
	ray->plane[1] = ray->old_plane * sin(ray->rotation) \
		+ ray->plane[1] * cos(ray->rotation);
}

int	deal_key(int keycode, t_data *data, t_ray *ray)
{
	if (keycode == UP)
		data->ray.walk_y = 1;
	else if (keycode == DOWN)
		ray->walk_y = -1;
	else if (keycode == A)
		ray->walk_x = 1;
	else if (keycode == D)
		ray->walk_x = -1;
	else if (keycode == RIGHT)
		ray->turn = -1;
	else if (keycode == LEFT)
		ray->turn = -1;
	else if (keycode == KEY_ESC)
		close_game(&data->mlxdata);
	return (0);
}

int	undeal_key(int keycode, t_ray *ray)
{
	if (keycode == UP)
		ray->walk_y = 0;
	else if (keycode == DOWN)
		ray->walk_y = 0;
	else if (keycode == A)
		ray->walk_x = 0;
	else if (keycode == D)
		ray->walk_x = 0;
	else if (keycode == RIGHT)
		ray->turn = 0;
	else if (keycode == LEFT)
		ray->turn = 0;
	return (0);
}

//===BASEADO NO LODEV EM UMA ÚNICA FUNÇÃO (MISTURADO COM A DE CIMA)===

/*int	deal_key(int keycode, t_data *data, t_ray *ray)
{
	ray->speed = 0.1;
    ray->rotation = 0;
	
	if (keycode == UP)
	{
		ft_putnbr_fd(keycode, 1);
		if (data->map.map[(int)(ray->playerpos[0] + ray->walk_y * \
		(ray->dir[0] * ray->speed))][(int)ray->playerpos[1]] == '0')
			ray->playerpos[0] += ray->walk_y * (ray->dir[0] * ray->speed);
		if (data->map.map[(int)(ray->playerpos[0])][(int)(ray->playerpos[1] + ray->walk_y * \
		(ray->dir[0] * ray->speed))] == '0')
			ray->playerpos[1] += ray->walk_y * (ray->dir[1]* ray->speed);
	}
	else if (keycode == DOWN)
	{
		ft_putnbr_fd(keycode, 1);
		if (data->map.map[(int)(ray->playerpos[0] + ray->walk_x * \
		(ray->plane[0] * ray->speed))][(int)ray->playerpos[1]] == '0')
			ray->playerpos[0] += ray->walk_x * (ray->plane[0] * ray->speed);
		if (data->map.map[(int)ray->playerpos[0]][(int)(ray->playerpos[1] + ray->walk_x * \
		(ray->plane[1] * ray->speed))] == '0')
			ray->playerpos[1] += ray->walk_x * (ray->plane[1] * ray->speed);
	}
	else if (keycode == A)
	{
		ft_putnbr_fd(keycode, 1);
		ray->old_dir = ray->dir[0];
      	ray->dir[0] = ray->dir[0] * cos(-ray->rotation) - ray->dir[1] * sin(-ray->rotation);
      	ray->dir[1] = ray->old_dir * sin(-ray->rotation) + ray->dir[1] * cos(-ray->rotation);
      	ray->old_plane = ray->plane[0];
      	ray->plane[0] = ray->plane[0] * cos(-ray->rotation) - ray->plane[1] * sin(-ray->rotation);
      	ray->plane[1] = ray->old_plane * sin(-ray->rotation) + ray->plane[1] * cos(-ray->rotation);
	}
	else if (keycode == D)
	{
		ft_putnbr_fd(keycode, 1);
		ray->old_dir = ray->dir[0];
      	ray->dir[0] = ray->dir[0] * cos(ray->rotation) - ray->dir[1] * sin(ray->rotation);
      	ray->dir[1] = ray->old_dir * sin(ray->rotation) + ray->dir[1] * cos(ray->rotation);
      	ray->old_plane = ray->plane[0];
      	ray->plane[0] = ray->plane[0] * cos(ray->rotation) - ray->plane[1] * sin(ray->rotation);
      	ray->plane[1] = ray->old_plane * sin(ray->rotation) + ray->plane[1] * cos(ray->rotation);
	}
	else if (keycode == RIGHT)
		ray->turn = -1;
	else if (keycode == LEFT)
		ray->turn = 1;
	else if (keycode == KEY_ESC)
		close_game(&data->mlxdata);
	return (0);
}*/

//===VI NO GOOGLE NÃO LEMBRO ONDE===

/*void move_player(t_data *data, float distance)
{
    float new_x;
    float new_y;

    new_x = data->ray.playerpos[0] + data->ray.dir[0] * distance;
    new_y = data->ray.playerpos[1] + data->ray.dir[1] * distance;

    if (data->map.map[(int)new_y][(int)new_x] == '0')
    {
        data->ray.playerpos[0] = new_x;
        data->ray.playerpos[1] = new_y;
    }
}

void rotate_player(t_data *data, float angle)
{
    float old_dir_x;
    float old_plane_x;

    old_dir_x = data->ray.dir[0];
    data->ray.dir[0] = data->ray.dir[0] * cos(angle) - data->ray.dir[1] * sin(angle);
    data->ray.dir[1] = old_dir_x * sin(angle) + data->ray.dir[1] * cos(angle);

    old_plane_x = data->ray.plane[0];
    data->ray.plane[0] = data->ray.plane[0] * cos(angle) - data->ray.plane[1] * sin(angle);
    data->ray.plane[1] = old_plane_x * sin(angle) + data->ray.plane[1] * cos(angle);
}

int deal_key(int keycode, t_data *data)
{
	data->ray.speed = 0.1;
    data->ray.rotation = 0;

    if (keycode == UP)
        move_player(data, 0.1);
    else if (keycode == DOWN)
        move_player(data, -0.1); 
    else if (keycode == A)
        rotate_player(data, -0.08);
    else if (keycode == D)
        rotate_player(data, 0.08);
	else if (keycode == KEY_ESC)
		close_game(&data->mlxdata);

    return 0;
}*/

//===FORMA QUE EU FIZ NO OPENGL===

/*int	deal_key(int keycode, t_ray *ray)
{
	if (keycode == A)
	{
    	ray->pa -= 0.1;
    	if (ray->pa < 0)
        	ray->pa += 2 * PI;
    	ray->pdx = cos(ray->pa) * 5;
    	ray->pdy = sin(ray->pa) * 5;
	}
	if (keycode == D) 
	{
    	ray->pa += 0.1;
    	if (ray->pa > 2 * PI)
        	ray->pa -= 2 * PI;
    	ray->pdx = cos(ray->pa) * 5;
    	ray->pdy = sin(ray->pa) * 5;
	}
	if(keycode == UP)
	{
		ray->playerpos[0] += ray->pdx;
		ray->playerpos[1] += ray->pdy;
	}
	if(keycode == DOWN)
	{
		ray->playerpos[0] -= ray->pdx;
		ray->playerpos[1] -= ray->pdy;
	}
	return(0);
}*/

//====CHATGPT INDICOU FAZER ISSO===

/*int key_press(int keycode, t_data *data) {
    // Marcar a tecla como pressionada (1)
    data->mlxdata.keys[keycode] = 1;

    return 0;
}

int key_release(int keycode, t_data *data) {
    // Marcar a tecla como não pressionada (0)
     data->mlxdata.keys[keycode] = 0;

    return 0;
}

int is_key_pressed(int keycode, t_data *data) {
    // Verificar se a tecla está pressionada (retorna 1 se estiver pressionada, 0 caso contrário)
    return  data->mlxdata.keys[keycode];
}

void update_player_position(t_data *data, double new_x, double new_y) 
{
    // Verificar se a nova posição é válida (não colide com obstáculos, limites do mapa, etc.)
    // Se a nova posição for válida, atualizar a posição do jogador
    data->ray.playerpos[0] = new_x;
    data->ray.playerpos[1] = new_y;
}

int	deal_key(t_data *data) {
    // Lógica de atualização do jogo (movimentação do jogador, colisões, etc.)

    // Verificar a entrada de teclado para movimentar o jogador
    if (is_key_pressed('W', data))
	{
        data->ray.playerpos[1] -= 1.0;
    }
	if (is_key_pressed('A', data))
	{
        data->ray.playerpos[0] -= 1.0;
    }
	if (is_key_pressed('S', data))
	{
         data->ray.playerpos[1] += 1.0;
    }
	if (is_key_pressed('D', data))
	{
         data->ray.playerpos[0] += 1.0;
    }
	return (0);
}*/

