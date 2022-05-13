/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:38:26 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/13 16:03:32 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	update(t_game *game)
{
	if (game->state == GAME)
	{
		game->params.mouse_coord.x = 0;
		game->params.mouse_coord.y = 0;
		printf("keycode foward: %d\n", game->keys.keys[FORWARD]);
		printf("forward is pressed: %d\n", game->params.inputs[game->keys.keys[FORWARD]]);
		if (game->params.inputs[game->keys.keys[RIGHT]])
			game->player_pos.x += 0.2f;
		if (game->params.inputs[game->keys.keys[LEFT]])
			game->player_pos.x -= 0.2f;
		if (game->params.inputs[game->keys.keys[FORWARD]])
			game->player_pos.y -= 0.2f;
		if (game->params.inputs[game->keys.keys[BACKWARD]])
			game->player_pos.y += 0.2f;
		// printf ("%.3f %.3f\n", game->player_pos.x, game->player_pos.y);
		mlx_mouse_move(game->mlx_win, 0, 0);
		mlx_mouse_hide();
	}
	else
		mlx_mouse_show();
}

void	raycast_all(t_game *game);

void	render(t_game *game)
{
	clear_image (&game->frame, rgba (30, 30, 45, 255));
	draw_panel(game);
	if (game->state == GAME)
		raycast_all (game);
}
