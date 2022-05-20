/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:17:14 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/20 17:01:54 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define CAM_SENSITIVITY 10000
# define MOVE_SPEED 0.2f

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define START_CHAR ' '
# define END_CHAR 'Z'
# define WIDTH_CHAR 16
# define HEIGHT_CHAR 16

# define MARGIN 10

# define MAIN_MENU 0
# define OPTIONS 1
# define GAME 2

/* Stupid forward declarations */

typedef struct s_game t_game;

/* Math */

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

t_rgba	rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a);
t_u32	rgba_to_trgb(t_rgba x);
t_rgba	trgb_to_rgba(t_u32 x);

typedef union u_vec2f
{
	t_f32		n[2];
	struct
	{
		t_f32	x;
		t_f32	y;
	};
}	t_vec2f;

t_vec2f	vec2f(t_f32 x, t_f32 y);
t_vec2f	vec2f_add(t_vec2f lhs, t_vec2f rhs);
t_vec2f	vec2f_sub(t_vec2f lhs, t_vec2f rhs);
t_vec2f	vec2f_neg(t_vec2f v);
t_vec2f	vec2f_mul(t_vec2f v, t_f32 s);
t_vec2f	vec2f_div(t_vec2f v, t_f32 s);
t_f32	vec2f_dot(t_vec2f a, t_vec2f b);
t_vec2f	vec2f_perp_cw(t_vec2f v);
t_vec2f	vec2f_perp_ccw(t_vec2f v);
t_f32	vec2f_len(t_vec2f v);
t_vec2f	vec2f_normalized(t_vec2f v);

typedef union u_recti
{
	t_int		n[4];
	struct
	{
		t_int	x;
		t_int	y;
		t_int	w;
		t_int	h;
	};
}	t_recti;

t_recti	recti(t_int x, t_int y, t_int w, t_int h);

typedef struct u_coord
{
	t_int		n[2];
	struct
	{
		t_int	x;
		t_int	y;
	};
}	t_coord;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

/* A t_map has all the information that is in a .cub file, in a somewhat
 * structured manner. This is not the in-game map that you see on screen,
 * where you have ennemies and stuff running around. */

typedef struct s_map
{
	t_str	tex_names[4];
	t_img	tex_img[4];
	t_rgba	colors[2];
	t_int	width;
	t_int	height;
	char	*data;
}	t_map;

typedef enum e_controls {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	SHOOT,
	NO_CHANGE
}	t_controls;

typedef struct s_keys
{
	t_controls	change_key;
	int			keys[5];
}	t_keys;

typedef struct s_param
{
	t_bool	inputs[1024];
	t_coord	mouse_coord;
}				t_param;

// @Cleanup (stefan): func is a bad name. Name this something UI related.
typedef void (*func) (t_game *game);

typedef struct s_ui
{
	t_uint	width;
	t_uint	height;
	t_int	top;
	t_int	left;
	t_str	str;
	t_rgba	bg_color;
	func	click;	
	// t_rgba	color;
}	t_ui;

typedef struct	s_panel
{
	t_ui	list_ui[10];
	t_uint	nb_ui;
}	t_panel;

typedef struct	s_game
{
	void	*mlx;
	void	*mlx_win;
	t_img	frame;
	t_img	font;
	t_panel	panels[3];
	t_int	state;
	t_map	map;
	t_param	params;
	t_keys	keys;
	t_vec2f	player_pos;
	t_vec2f	cam_dir;
}	t_game;

void	init_game(t_game *game);
int		tick(void *params);
void	update(t_game *game);
void	update_player(t_game *game);
void	render(t_game *game);

/* Font */

void	init_font(t_game *game);
void	draw_char(t_game *game, char c, int x, int y);
void	draw_str(t_game *game, t_str str, int x, int y);

/* Image */

t_bool	init_img(t_game *game, t_img *img, int width, int height);
t_bool	init_img_xpm(t_game *game, t_img *img, t_str filename);
void	destroy_img(t_game *game, t_img *img);
void	clear_img(t_img *img, t_rgba col);
void	set_px(t_img *img, int x, int y, t_rgba color);
t_rgba	get_px(t_img *img, int x, int y);

int		keydown(int keycode, void *in);
int		keyup(int keycode, void *in);
int		mouse_press(int keycode, int x, int y, void *in);
int		mouse_release(int keycode, int x, int y, void *in);
int		mouse_move(int x, int y, void *in);

void	click_panel(t_game *game, int x, int y);
void	create_panels(t_game *game);
void	draw_panel(t_game *game);

t_bool	eprint(t_cstr fmt, ...);
t_bool	parse_map(t_map *map, t_cstr filename);

t_bool	is_key_down(t_game *game, int code);

/* Raycasting */

typedef struct s_hit
{
	t_bool	hit;
	t_vec2f	dir;
	t_vec2f	delta_dist;
	t_vec2f	side_dist;
	t_int	side;
	t_coord	coord;
}	t_hit;

t_hit	raycast(t_game *game, t_vec2f orig, t_vec2f dir, t_f32 len);

/* Drawing */

/*
void	draw_point(t_game *game, t_int x, t_int y, t_f32 size, t_rgba col);
void	draw_rect(t_game *game, t_int x, t_int y, t_int w, t_int h, t_rgba c);
void	draw_circle(t_game *game, t_int x, t_int y, t_f32 rad, t_rgba c);
*/
void	draw_img(t_game *game, t_int x, t_int y, t_img *img);
void	draw_img_part(t_game *game, t_coord at, t_img *img, t_recti r);

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

#endif
