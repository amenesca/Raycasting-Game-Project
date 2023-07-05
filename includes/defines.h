/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:54:55 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 15:57:10 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define FLOOR
# define CEILING

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

# ifdef __linux__

enum	e_keycode
{
	UP = 119,
	DOWN = 115,
	A = 97,
	D = 100,
	LEFT = 65361,
	RIGHT = 65363,
	KEY_ESC = 65307
};
# else

enum	e_keycode
{
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	KEY_ESC = 53
};
# endif

#endif