#ifndef DEFINES_H
# define DEFINES_H

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define FLOOR
# define CEILING

# define w 640
# define h 480

#define GREEN_PIXEL 0x00FF00
#define RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0xFFFFFF
#define  BLACK_PIXEL 0x000000

# ifdef __linux__

enum	e_keycode
{
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100,
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
