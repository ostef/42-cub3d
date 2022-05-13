/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:52:20 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/12 14:07:28 by ljourand         ###   ########lyon.fr   */
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

void	create_panels(t_game *game)
{
	t_panel	menu;

	ft_memset(&menu, 0, sizeof(t_panel));
	game->panels[GAME] = menu;
	game->panels[OPTIONS] = menu;
	create_ui(&menu, (SCREEN_HEIGHT - (HEIGHT_CHAR + MARGIN * 2) * 4) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("play")) / 2 - MARGIN, "play", play);
	create_ui(&menu, (SCREEN_HEIGHT - (HEIGHT_CHAR + MARGIN * 2)) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("options")) / 2 - MARGIN, "options", option);
	create_ui(&menu, (SCREEN_HEIGHT + (HEIGHT_CHAR + MARGIN * 2) * 2) / 2, (SCREEN_WIDTH - WIDTH_CHAR * ft_strlen("exit")) / 2 - MARGIN, "exit", exit_click);
	game->panels[MAIN_MENU] = menu;
	game->state = MAIN_MENU;
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
}
