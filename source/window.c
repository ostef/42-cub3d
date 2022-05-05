/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:02:29 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/05 16:58:03 by ljourand         ###   ########lyon.fr   */
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

int	tick(void *params)
{
	t_game *game;

	game = (t_game *)params;
	if (!game->mouse_enabled)
	{
		game->params.mouse_coord.x = 0;
		game->params.mouse_coord.y = 0;
		mlx_mouse_move(game->mlx.window, 0, 0);
	}
	return (0);
}

void	init_game(t_game *game)
{
	ft_memset(&game->params, 0, sizeof(t_param));
	game->mlx.mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cube3d");
	mlx_hook(game->mlx.window, MOUSE_PRESS, 0L, mouse_press, &game->params.inputs);
	mlx_hook(game->mlx.window, MOUSE_RELEASE, 0L, mouse_release, &game->params.inputs);
	mlx_hook(game->mlx.window, MOUSE_MOVE, 0L, mouse_move, &game);
	mlx_hook(game->mlx.window, KEY_PRESS, 0L, keydown, &game->params.inputs);
	mlx_hook(game->mlx.window, KEY_RELEASE, 0L, keyup, &game->params.inputs);
	mlx_hook(game->mlx.window, DESTROY_NOTIFY, 0L, destroy, NULL);
	start_game(game);
	mlx_loop_hook(game->mlx.mlx, tick, game);
	mlx_loop(game->mlx.mlx);
}

void	init_keys(t_keys *keys)
{
	keys->forward = KEY_UP;
	keys->backward = KEY_DOWN;
	keys->left = KEY_LEFT;
	keys->right = KEY_RIGHT;
	keys->shoot = KEY_CTRL;
}
