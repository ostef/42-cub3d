/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:41:30 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/20 15:36:22 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	update_player(t_game *game)
{
	t_vec2f	movement;
	t_hit	hit;

	movement = vec2f (
		(is_key_down (game, RIGHT) - is_key_down (game, LEFT)),
		(is_key_down (game, FORWARD) - is_key_down (game, BACKWARD))
	);
	movement = vec2f_mul (vec2f_normalized (movement), MOVE_SPEED);
	movement = vec2f_add (
		vec2f_mul (vec2f_perp_ccw (game->cam_dir), movement.x),
		vec2f_mul (game->cam_dir, movement.y)
	);
	hit = raycast (game, game->player_pos,
		vec2f_normalized (movement), vec2f_len (movement));
	if (hit.hit)
		movement = vec2f_mul (hit.dir, hit.dist);
	game->player_pos = vec2f_add (game->player_pos, movement);
}
