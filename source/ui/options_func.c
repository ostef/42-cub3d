/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:48:51 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/23 13:49:02 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	set_forward(t_game *game)
{
	game->keys.change_key = FORWARD;
}

void	set_backward(t_game *game)
{
	game->keys.change_key = BACKWARD;
}

void	set_left(t_game *game)
{
	game->keys.change_key = LEFT;
}

void	set_right(t_game *game)
{
	game->keys.change_key = RIGHT;
}

void	back(t_game *game)
{
	game->keys.change_key = NO_CHANGE;
	game->state = MAIN_MENU;
}
