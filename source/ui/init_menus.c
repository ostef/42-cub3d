/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:52:33 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/23 13:53:21 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	play(t_game *game)
{
	mlx_mouse_hide();
	game->state = GAME;
}

static void	option(t_game *game)
{
	game->state = OPTIONS;
}

static void	exit_click(t_game *game)
{
	exit(EXIT_SUCCESS);
	(void)game;
}

void	init_main_menu(t_game *game)
{
	t_panel	menu;
	t_coord	coord;

	ft_memset(&menu, 0, sizeof(t_panel));
	game->panels[GAME] = menu;
	game->panels[OPTIONS] = menu;
	coord.y = (SCREEN_HEIGHT - (HEIGHT_CHAR + MARGIN * 2) * 4) / 2;
	coord.x = (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("play")) / 2 - MARGIN;
	create_ui(&menu, coord, "play", play);
	coord.y += MARGIN * 3 + HEIGHT_CHAR;
	coord.x = (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("options")) / 2 - MARGIN;
	create_ui(&menu, coord, "options", option);
	coord.y += MARGIN * 3 + HEIGHT_CHAR;
	coord.x = (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("exit")) / 2 - MARGIN;
	create_ui(&menu, coord, "exit", exit_click);
	game->panels[MAIN_MENU] = menu;
}

void	init_option_menu(t_game *game)
{
	t_panel	options;
	t_coord	coord;

	ft_memset(&options, 0, sizeof(t_panel));
	game->panels[GAME] = options;
	game->panels[OPTIONS] = options;
	coord.y = (SCREEN_HEIGHT - (HEIGHT_CHAR + MARGIN * 2) * 6) / 2;
	coord.x = (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("forward")) / 2 - MARGIN;
	create_ui(&options, coord, "forward", set_forward);
	coord.y += MARGIN * 3 + HEIGHT_CHAR;
	coord.x = (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("backward")) / 2 - MARGIN;
	create_ui(&options, coord, "backward", set_backward);
	coord.y += MARGIN * 3 + HEIGHT_CHAR;
	coord.x = (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("left")) / 2 - MARGIN;
	create_ui(&options, coord, "left", set_left);
	coord.y += MARGIN * 3 + HEIGHT_CHAR;
	coord.x = (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("right")) / 2 - MARGIN;
	create_ui(&options, coord, "right", set_right);
	coord.y += MARGIN * 3 + HEIGHT_CHAR;
	coord.x = (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("back")) / 2 - MARGIN;
	create_ui(&options, coord, "back", back);
	game->panels[OPTIONS] = options;
}
