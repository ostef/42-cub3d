/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:43:57 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/02 17:48:22 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	keydown(int keycode, void *game)
{
	t_game	*gam;

	printf("keycode: %d\n", keycode);
	gam = (t_game *)game;
	if (keycode == KEY_Q)
		stop_game(game);
	if (keycode == KEY_A)
		start_game(game);
	if (keycode == 53)
	{
		exit(0);
	}
	gam->params.inputs[keycode] = TRUE;
	return (0);
}

int	keyup(int keycode, void *game)
{
	t_game	*gam;

	gam = (t_game *)game;
	if (keycode == 53)
	{
		exit(0);
	}
	gam->params.inputs[keycode] = FALSE;
	return (0);
}

int	mouse_press(int keycode, int x, int y, void *in)
{
	t_bool	*inputs;

	printf("keycode mouse: %d\n", keycode + 500);
	inputs = (t_bool *)in;
	inputs[keycode + 500] = TRUE;
	return (0);
	(void)x;
	(void)y;
}

int	mouse_release(int keycode, int x, int y, void *in)
{
	t_bool	*inputs;

	inputs = (t_bool *)in;
	inputs[keycode + 500] = FALSE;
	return (0);
	(void)x;
	(void)y;
}

int	mouse_move(int x, int y, void *mouse_coord)
{
	t_coord	*coord;

	coord = (t_coord *)mouse_coord;
	printf("mouse move: x: %d, y: %d\n", x, y);
	coord->x += x;
	coord->y += y;
	return (0);
	(void)x;
	(void)y;
}
