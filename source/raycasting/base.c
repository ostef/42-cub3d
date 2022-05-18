/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:02:58 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/18 18:24:28 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	raycast_all(t_game *game)
{
	t_int	x;
	t_vec2f	plane;
	t_vec2f	ray_dir;
	t_vec2f	side_dist;
	t_vec2f	delta_dist;
	t_coord	step;
	t_coord	map_coord;
	t_int	side;
	t_f32	perp_wall_dist;

	game->params.mouse_coord.x = 0;
	game->params.mouse_coord.y = 0;
	plane.x = -game->cam_dir.y;
	plane.y = game->cam_dir.x;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		map_coord.x = (int)game->player_pos.x;
		map_coord.y = (int)game->player_pos.y;
		ray_dir.x = game->cam_dir.x + plane.x * (2 * x / (t_f32)SCREEN_WIDTH - 1);
		ray_dir.y = game->cam_dir.y + plane.y * (2 * x / (t_f32)SCREEN_WIDTH - 1);
		delta_dist.x = ft_absf (1 / ray_dir.x);
		delta_dist.y = ft_absf (1 / ray_dir.y);
		if (ray_dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (game->player_pos.x - map_coord.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (map_coord.x + 1.0 - game->player_pos.x) * delta_dist.x;
		}
		if (ray_dir.y < 0)
		{
			step.y = -1;
			side_dist.y = (game->player_pos.y - map_coord.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (map_coord.y + 1.0 - game->player_pos.y) * delta_dist.y;
		}
		while (TRUE)
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				map_coord.x += step.x;
				side = 0;
			}
			else
			{
				side_dist.y += delta_dist.y;
				map_coord.y += step.y;
				side = 1;
			}
			if (map_coord.y < 0 || map_coord.y >= game->map.height)
				ft_panic ("Y out of bounds.");
			if (map_coord.x < 0 || map_coord.x >= game->map.width)
				ft_panic ("X out of bounds.");
			if (game->map.data[map_coord.y * game->map.width + map_coord.x] == '1')
				break ;
		}
		if (side == 0)
			perp_wall_dist = (side_dist.x - delta_dist.x);
		else
			perp_wall_dist = (side_dist.y - delta_dist.y);
		int line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
		int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;
		float wall_x;
		if (side == 0)
			wall_x = game->player_pos.y + perp_wall_dist * ray_dir.y;
		else
			wall_x = game->player_pos.x + perp_wall_dist * ray_dir.x;
		wall_x -= floor (wall_x);
		int tex_x = (int)(wall_x * game->map.tex_img[0].width);
		if (side == 0 && ray_dir.x > 0)
			tex_x = game->map.tex_img[0].width - tex_x - 1;
		if (side == 1 && ray_dir.y < 0)
			tex_x = game->map.tex_img[0].width - tex_x - 1;
		for (int y = draw_start; y < draw_end; y += 1)
		{
			int tex_y = (y + line_height / 2 - SCREEN_HEIGHT / 2) * game->map.tex_img[0].height / (line_height);
			tex_y = ft_clamp (tex_y, 0, game->map.tex_img[0].height - 1);
			// set_px (&game->frame, x, y, rgba (255, 0, 0, 255));
			set_px(&game->frame, x, y, get_px(
				&game->map.tex_img[0],
				tex_x,
				tex_y
			));
		}
		x += 1;
	}
}
