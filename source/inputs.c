/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:43:57 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/13 17:33:12 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	keydown(int keycode, void *game)
{
	t_game	*gam;

	// printf("keycode: %d\n", keycode);
	gam = (t_game *)game;
	if (keycode == KEY_ESCAPE)
	{
		exit(0);
	}
	gam->params.inputs[keycode] = TRUE;
	if (gam->keys.change_key != NO_CHANGE)
	{
		gam->keys.keys[gam->keys.change_key] = keycode;
		gam->keys.change_key = NO_CHANGE;
	}
	return (0);
}

int	keyup(int keycode, void *game)
{
	t_game	*gam;

	gam = (t_game *)game;
	gam->params.inputs[keycode] = FALSE;
	return (0);
}

int	mouse_press(int keycode, int x, int y, void *in)
{
	t_game	*game;

	// printf("keycode mouse: %d\n", keycode + 500);
	game = (t_game *)in;
	game->params.inputs[keycode + 500] = TRUE;
	if (game->keys.change_key != NO_CHANGE)
	{
		game->keys.keys[game->keys.change_key] = keycode + 500;
		game->keys.change_key = NO_CHANGE;
	}
	click_panel(game, x, y);
	return (0);
	(void)x;
	(void)y;
}

int	mouse_release(int keycode, int x, int y, void *in)
{
	t_game	*game;

	game = (t_game *)in;
	game->params.inputs[keycode + 500] = FALSE;
	return (0);
	(void)x;
	(void)y;
}

int	mouse_move(int x, int y, void *g)
{
	t_game	*game;

	game = (t_game *)g;
	// printf("mouse move: x: %d, y: %d\n", x, y);
	if (game->state != GAME)
	{
		game->params.mouse_coord.x = x;
		game->params.mouse_coord.y = y;
	}
	else
	{
		game->params.mouse_coord.x += x - SCREEN_WIDTH / 2;
		game->params.mouse_coord.y += y - SCREEN_HEIGHT / 2;
	}
	return (0);
	(void)x;
	(void)y;
}
