/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:38:26 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/23 13:59:27 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

void	update(t_game *game)
{
	if (game->state == GAME)
	{
		game->cam_dir.x = cos(((double)game->params.mouse_coord.x
					/ CAM_SENSITIVITY * PI) + atan2(game->cam_dir.y,
					game->cam_dir.x));
		game->cam_dir.y = sin(((double)game->params.mouse_coord.x
					/ CAM_SENSITIVITY * PI) + atan2(game->cam_dir.y,
					game->cam_dir.x));
		mlx_mouse_move(game->mlx_win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		game->params.mouse_coord.x = 0;
		game->params.mouse_coord.y = 0;
		update_player (game);
	}
}

void	raycast_all(t_game *game);

void	render(t_game *game)
{
	clear_img (&game->frame, rgba (30, 30, 45, 255));
	draw_panel(game);
	if (game->state == GAME)
		raycast_all (game);
}
