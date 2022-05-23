/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:52:20 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/23 13:56:45 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	create_ui(t_panel *panel, t_coord coord, t_str str,
		void (*func) (t_game *))
{
	t_ui	ui;

	ft_memset(&ui, 0, sizeof(t_ui));
	ui.top = coord.y;
	ui.left = coord.x;
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
	t_ui	ui;

	panel = game->panels[game->state];
	i = 0;
	while (i < panel.nb_ui)
		draw_ui(game, panel.list_ui[i++]);
	if (game->state == OPTIONS && game->keys.change_key != NO_CHANGE)
	{
		ft_memset(&ui, 0, sizeof(t_ui));
		ui.top = SCREEN_HEIGHT / 2;
		ui.left = SCREEN_WIDTH / 2 - ft_strlen("type a key:")
			* WIDTH_CHAR / 2 - MARGIN;
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
