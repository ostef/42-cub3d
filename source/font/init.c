/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:20:10 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/17 16:56:15 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_font(t_game *game)
{
	init_img_xpm(game, &game->font, "data/images/font.xpm");
}

void	draw_char(t_game *game, char c, int x, int y)
{
	int		xx;
	int		yy;
	t_rgba	color;
	
	c = ft_to_upper(c);
	if (c < START_CHAR || c > END_CHAR)
		return ;
	xx = 0;
	while (xx < WIDTH_CHAR)
	{
		yy = 0;
		while (yy < HEIGHT_CHAR)
		{
			color = get_px(&game->font, xx + (c - START_CHAR) * WIDTH_CHAR, yy);
			set_px(&game->frame, x + xx, y + yy, color);
			yy++;
		}
		xx++;
	}
}

void	draw_str(t_game *game, t_str str, int x, int y)
{
	t_uint	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		draw_char(game, str[i], x + i * WIDTH_CHAR, y);
		i++;
	}
}
