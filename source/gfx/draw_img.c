/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:05:02 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/17 17:10:48 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_img(t_game *game, t_int x, t_int y, t_img *img)
{
	t_int	i;
	t_int	j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width
			&& x + j < game->frame.width && y + i < game->frame.height)
		{
			set_px (&game->frame, x + j, y + i, get_px (img, j, i));
			j += 1;
		}
		i += 1;
	}
}

void	draw_img_part(t_game *game, t_coord at, t_img *img, t_recti r)
{
	t_int	i;
	t_int	j;

	i = 0;
	while (i < r.h)
	{
		j = 0;
		while (j < r.w
			&& at.x + j < game->frame.width && at.y + i < game->frame.height)
		{
			set_px (&game->frame, at.x + j, at.y + i, get_px (img, r.x + j, r.y + i));
			j += 1;
		}
		i += 1;
	}
}
