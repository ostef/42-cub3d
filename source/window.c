/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:02:29 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/13 13:48:12 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	destroy(int keycode, void *null)
{
	exit(0);
	(void)keycode;
	(void)null;
	return (0);
}

void	clear_frame(t_game *game)
{
	t_image	img;

	img = game->frame;
	ft_memset(img.addr, 0, SCREEN_HEIGHT * img.line_length + SCREEN_WIDTH * (img.bits_per_pixel / 8));
}

int	tick(void *params)
{
	t_game *game;

	game = (t_game *)params;
	// clear_frame(game);
	if (game->state == GAME)
	{
		mlx_mouse_hide();
		game->params.mouse_coord.x = 0;
		game->params.mouse_coord.y = 0;
		mlx_mouse_move(game->mlx_win, 0, 0);
	}
	else
		mlx_mouse_show();
	draw_panel(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->frame.mlx_img, 0, 0);
	return (0);
}

void	init_game(t_game *game)
{
	ft_memset(&game->params, 0, sizeof(t_param));
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cube3d");
	init_image(game, &game->frame, SCREEN_WIDTH, SCREEN_HEIGHT);
	init_font(game);
	create_panels(game);
	mlx_hook(game->mlx_win, MOUSE_PRESS, 0L, mouse_press, game);
	mlx_hook(game->mlx_win, MOUSE_RELEASE, 0L, mouse_release, game);
	mlx_hook(game->mlx_win, MOUSE_MOVE, 0L, mouse_move, game);
	mlx_hook(game->mlx_win, KEY_PRESS, 0L, keydown, game);
	mlx_hook(game->mlx_win, KEY_RELEASE, 0L, keyup, game);
	mlx_hook(game->mlx_win, DESTROY_NOTIFY, 0L, destroy, NULL);
	// draw_str(game, "TEST", 0, 0);
	mlx_loop_hook(game->mlx, tick, game);
	mlx_loop(game->mlx);
}

void	init_keys(t_keys *keys)
{
	keys->forward = KEY_UP;
	keys->backward = KEY_DOWN;
	keys->left = KEY_LEFT;
	keys->right = KEY_RIGHT;
	keys->shoot = KEY_CTRL;
}
