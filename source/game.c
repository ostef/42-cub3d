/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:38:26 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/17 17:11:26 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	update(t_game *game)
{
	if (game->state == GAME)
	{
		game->params.mouse_coord.x = 0;
		game->params.mouse_coord.y = 0;
		if (game->params.inputs[KEY_D])
			game->player_pos.x += 0.2f;
		if (game->params.inputs[KEY_A])
			game->player_pos.x -= 0.2f;
		if (game->params.inputs[KEY_W])
			game->player_pos.y -= 0.2f;
		if (game->params.inputs[KEY_S])
			game->player_pos.y += 0.2f;
		printf ("%.3f %.3f\n", game->player_pos.x, game->player_pos.y);
		mlx_mouse_move(game->mlx_win, 0, 0);
		mlx_mouse_hide();
	}
	else
		mlx_mouse_show();
}

void	raycast_all(t_game *game);

void	render(t_game *game)
{
	clear_img (&game->frame, rgba (30, 30, 45, 255));
	draw_panel(game);
	if (game->state == GAME)
		raycast_all (game);
}
