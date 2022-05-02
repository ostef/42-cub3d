/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pause.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:45:39 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/02 17:45:00 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	start_game(t_game *game)
{
	printf("start game\n");
	game->mouse_enabled = FALSE;
	mlx_mouse_hide();
}

void	stop_game(t_game *game)
{
	printf("stop game\n");
	game->mouse_enabled = FALSE;
	mlx_mouse_show();
}
