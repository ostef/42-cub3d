/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:52:20 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/13 17:03:02 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	create_ui(t_panel *panel, t_uint top, t_uint left, t_str str, void (*func) (t_game *))
{
	t_ui	ui;

	ft_memset(&ui, 0, sizeof(t_ui));
	ui.top = top;
	ui.left = left;
	ui.width = ft_strlen(str) * WIDTH_CHAR + MARGIN * 2;
	ui.height = HEIGHT_CHAR + MARGIN * 2;
	ui.bg_color.r = 100;
	ui.bg_color.g = 100;
	ui.bg_color.b = 100;
	ui.bg_color.a = 255;
	ui.click = func;
	ui.str = ft_strdup(str, ft_heap());
	panel->list_ui[panel->nb_ui] = ui;
	panel->nb_ui++;
}

void	click_panel(t_game *game, int x, int y)
{
	t_panel	panel;
	t_uint	i;
	t_ui	ui;

	panel = game->panels[game->state];
	i = 0;
	while (i < panel.nb_ui)
	{
		ui = panel.list_ui[i];
		if (x >= ui.left && x <= ui.left + (t_int)ui.width)
		{
			if (y >= ui.top && y <= ui.top + (t_int)ui.height)
			{
				ui.click(game);
			}
		}
		i++;
	}
}

void	play(t_game *game)
{
	printf("play\n");
	game->state = GAME;
	(void)game;
}

void	option(t_game *game)
{
	printf("options\n");
	game->state = OPTIONS;
	(void)game;
}

void	exit_click(t_game *game)
{
	printf("exit\n");
	exit(EXIT_SUCCESS);
	(void)game;
}

void	init_main_menu(t_game *game)
{
	t_panel	menu;

	ft_memset(&menu, 0, sizeof(t_panel));
	game->panels[GAME] = menu;
	game->panels[OPTIONS] = menu;
	create_ui(&menu, (SCREEN_HEIGHT - (HEIGHT_CHAR + MARGIN * 2) * 4) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("play")) / 2 - MARGIN, "play", play);
	create_ui(&menu, (SCREEN_HEIGHT - (HEIGHT_CHAR + MARGIN * 2)) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("options")) / 2 - MARGIN, "options", option);
	create_ui(&menu, (SCREEN_HEIGHT + (HEIGHT_CHAR + MARGIN * 2) * 2) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("exit")) / 2 - MARGIN, "exit", exit_click);
	game->panels[MAIN_MENU] = menu;
}

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

void	set_shoot(t_game *game)
{
	game->keys.change_key = SHOOT; 
}

void	back(t_game *game)
{
	game->keys.change_key = NO_CHANGE;
	game->state = MAIN_MENU; 
}

void	init_option_menu(t_game *game)
{
	t_panel	options;

	ft_memset(&options, 0, sizeof(t_panel));
	game->panels[GAME] = options;
	game->panels[OPTIONS] = options;
	create_ui(&options, (SCREEN_HEIGHT - (HEIGHT_CHAR + MARGIN * 2) * 6) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("forward")) / 2 - MARGIN, "forward", set_forward);
	create_ui(&options, (SCREEN_HEIGHT - (HEIGHT_CHAR + MARGIN * 2) * 4) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("backward")) / 2 - MARGIN, "backward", set_backward);
	create_ui(&options, (SCREEN_HEIGHT - (HEIGHT_CHAR + MARGIN * 2) * 2) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("left")) / 2 - MARGIN, "left", set_left);
	create_ui(&options, (SCREEN_HEIGHT + (HEIGHT_CHAR + MARGIN * 2) * 2) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("right")) / 2 - MARGIN, "right", set_right);
	create_ui(&options, (SCREEN_HEIGHT + (HEIGHT_CHAR + MARGIN * 2) * 4) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("shoot")) / 2 - MARGIN, "shoot", set_right);
	create_ui(&options, (SCREEN_HEIGHT + (HEIGHT_CHAR + MARGIN * 2) * 7) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("back")) / 2 - MARGIN, "back", back);
	game->panels[OPTIONS] = options;
}

void	create_panels(t_game *game)
{
	game->state = MAIN_MENU;
	init_main_menu(game);
	init_option_menu(game);
}

void	draw_ui(t_game *game, t_ui ui)
{
	t_uint	x;
	t_uint	y;

	x = 0;
	while (x < ui.width)
	{
		y = 0;
		while (y < ui.height)
		{		
			set_px(&game->frame, x + ui.left, y + ui.top, ui.bg_color);
			y++;
		}
		x++;
	}
	draw_str(game, ui.str, ui.left + MARGIN, ui.top + MARGIN);
	(void)game;
}

void	draw_panel(t_game *game)
{
	t_panel	panel;
	t_uint	i;

	panel = game->panels[game->state];
	i = 0;
	while (i < panel.nb_ui)
	{
		draw_ui(game, panel.list_ui[i]);
		i++;
	}
	if (game->state == OPTIONS && game->keys.change_key != NO_CHANGE)
	{
		t_ui	ui;

		ft_memset(&ui, 0, sizeof(t_ui));
		ui.top = SCREEN_WIDTH / 2;
		ui.left = SCREEN_HEIGHT / 2;
		ui.width = ft_strlen("type a key:") * WIDTH_CHAR + MARGIN * 2;
		ui.height = HEIGHT_CHAR + MARGIN * 2;
		ui.bg_color.r = 100;
		ui.bg_color.g = 100;
		ui.bg_color.b = 100;
		ui.bg_color.a = 255;
		ui.click = NULL;
		ui.str = "type a key:";
		draw_ui(game, ui);
	}
}
