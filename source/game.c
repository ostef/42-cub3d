/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:38:26 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/13 17:38:51 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

static const double sensitivity = 10000;

void	update(t_game *game)
{
	if (game->state == GAME)
	{
		game->cam_dir.x = cos(((double)game->params.mouse_coord.x / sensitivity * PI) + atan2(game->cam_dir.y, game->cam_dir.x));
		game->cam_dir.y = sin(((double)game->params.mouse_coord.x / sensitivity * PI) + atan2(game->cam_dir.y, game->cam_dir.x));
		printf("cam x: %lf\n", game->cam_dir.x);
		printf("cam y: %lf\n", game->cam_dir.y);
		mlx_mouse_move(game->mlx_win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		game->params.mouse_coord.x = 0;
		game->params.mouse_coord.y = 0;
		if (game->params.inputs[game->keys.keys[RIGHT]])
			game->player_pos.x += 0.2f;
		if (game->params.inputs[game->keys.keys[LEFT]])
			game->player_pos.x -= 0.2f;
		if (game->params.inputs[game->keys.keys[FORWARD]])
			game->player_pos.y -= 0.2f;
		if (game->params.inputs[game->keys.keys[BACKWARD]])
			game->player_pos.y += 0.2f;
		// printf ("%.3f %.3f\n", game->player_pos.x, game->player_pos.y);
		// mlx_mouse_move(game->mlx_win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
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
