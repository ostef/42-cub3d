/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:17:14 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/03 16:19:52 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include "mlx.h"
# include "libft.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef enum e_x11event
{
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	MOUSE_PRESS = 4,
	MOUSE_RELEASE = 5,
	MOUSE_MOVE = 6,
	ENTER_NOTIFY = 7,
	LEAVE_NOTIFY = 8,
	FOCUS_IN = 9,
	FOCUS_OUT = 10,
	KEYMAP_NOTIFY = 11,
	EXPOSE = 12,
	GRAPHICS_EXPOSE = 13,
	NO_EXPOSE = 14,
	VISIBILITY_NOTIFY = 15,
	CREATE_NOTIFY = 16,
	DESTROY_NOTIFY = 17,
	UNMAP_NOTIFY = 18,
	MAP_NOTIFY = 19,
	MAP_REQUEST = 20,
	REPARENT_NOTIFY = 21,
	CONFIGURE_NOTIFY = 22,
	CONFIGURE_REQUEST = 23,
	GRAVITY_NOTIFY = 24,
	RESIZE_REQUEST = 25,
	CIRCULATE_NOTIFY = 26,
	CIRCULATE_REQUEST = 27,
	PROPERTY_NOTIFY = 28,
	SELECTION_CLEAR = 29,
	SELECTION_REQUEST = 30,
	SELECTION_NOTIFY = 31,
	COLORMAP_NOTIFY = 32,
	CLIENT_MESSAGE = 33,
	MAPPING_NOTIFY = 34,
	GENERIC_EVENT = 35,
	LAST_EVENT = 36,
}	t_x11event;

typedef enum e_key
{
	KEY_A = 0,
	KEY_B = 11,
	KEY_C = 8,
	KEY_D = 2,
	KEY_E = 14,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 46,
	KEY_N = 45,
	KEY_O = 31,
	KEY_P = 35,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_S = 1,
	KEY_T = 17,
	KEY_U = 32,
	KEY_V = 9,
	KEY_W = 13,
	KEY_X = 7,
	KEY_Y = 16,
	KEY_Z = 6,
	KEY_ZERO = 29,
	KEY_ONE = 18,
	KEY_TWO = 19,
	KEY_THREE = 20,
	KEY_FOUR = 21,
	KEY_FIVE = 23,
	KEY_SIX = 22,
	KEY_SEVEN = 26,
	KEY_EIGHT = 28,
	KEY_NINE = 25,
	KEY_BRACE_R = 30,
	KEY_BRACE_L = 33,
	KEY_TAB = 48,
	KEY_PLUS = 69,
	KEY_MINUS = 78,
	KEY_SEMI = 41,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126,
	KEY_ESCAPE = 53,
	KEY_LESS = 43,
	KEY_GREATER = 47,
	KEY_SPACE = 49,
	KEY_PAGE_UP = 116,
	KEY_PAGE_DOWN = 121,
	KEY_F2 = 120,
	KEY_CTRL = 256,
}	t_key;

typedef union u_rgba
{
	struct
	{
		t_u8	r;
		t_u8	g;
		t_u8	b;
		t_u8	a;
	};
	t_u8		n[4];
}	t_rgba;

/* A t_map has all the information that is in a .cub file, in a somewhat
 * structured manner. This is not the in-game map that you see on screen,
 * where you have ennemies and stuff running around. */

typedef struct s_map
{
	t_str	tex_names[4];
	t_rgba	colors[2];
	t_int	width;
	t_int	height;
	char	*data;
}	t_map;

typedef struct	s_image
{
	void	*mlx_img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct	s_keys
{
	int	forward;
	int	backward;
	int	left;
	int	right;
	int	shoot;
}				t_keys;

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_vec2f
{
	t_f32	x;
	t_f32	y;
}	t_vec2f;

typedef struct s_param
{
	t_bool	inputs[1024];
	t_coord	mouse_coord;
}				t_param;

typedef struct	s_game
{
	void	*mlx;
	void	*mlx_win;
	t_image	frame;
	t_bool	mouse_enabled;
	t_map	map;
	t_param	params;
	t_vec2f	player_pos;
	t_vec2f	cam_dir;
}				t_game;

void	init_game(t_game *game);
void	start_game(t_game *game);
void	stop_game(t_game *game);
int		tick(void *params);

int		keydown(int keycode, void *in);
int		keyup(int keycode, void *in);
int		mouse_press(int keycode, int x, int y, void *in);
int		mouse_release(int keycode, int x, int y, void *in);
int		mouse_move(int x, int y, void *in);

t_bool	eprint(t_cstr fmt, ...);
t_bool	parse_map(t_map *map, t_cstr filename);

/* Image */

void	init_image(t_game *game, t_image *img, int width, int height);
void	set_px(t_image *img, int x, int y, t_rgba color);
t_rgba	get_px(t_image *img, int x, int y);

/* Math */

t_u32	rgba_to_trgb(t_rgba x);
t_rgba	trgb_to_rgba(t_u32 x);

#endif
