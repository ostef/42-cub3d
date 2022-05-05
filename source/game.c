/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:38:26 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/05 17:39:09 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	update(t_game *game)
{
	game->params.mouse_coord.x = 0;
	game->params.mouse_coord.y = 0;
}

void	render(t_game *game)
{
	clear_image (&game->frame, rgba (0, 0, 0, 255));
	for (int y = 0; y < game->frame.height; y += 1)
	{
		for (int x = 0; x < game->frame.width; x += 1)
		{
			set_px (&game->frame, x, y, rgba (
				(t_u8)(x / (t_f32)game->frame.width * 255),
				(t_u8)(y / (t_f32)game->frame.height * 255),
				0,
				255
			));
		}
	}
}
