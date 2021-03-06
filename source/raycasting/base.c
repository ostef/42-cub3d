/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:02:58 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/20 17:16:45 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	raycast_all(t_game *game)
{
	t_int	x;
	t_vec2f	plane;
	t_vec2f	ray_dir;
	t_f32	perp_wall_dist;
	t_hit	hit;

	plane = vec2f_perp_ccw (game->cam_dir);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ray_dir.x = game->cam_dir.x + plane.x * (2 * x / (t_f32)SCREEN_WIDTH - 1);
		ray_dir.y = game->cam_dir.y + plane.y * (2 * x / (t_f32)SCREEN_WIDTH - 1);
		hit = raycast (game, game->player_pos, ray_dir, INFINITY);
		int draw_start = SCREEN_HEIGHT / 2;
		int draw_end   = SCREEN_HEIGHT / 2;
		if (hit.hit)
		{
			if (hit.side == 0)
				perp_wall_dist = (hit.side_dist.x - hit.delta_dist.x);
			else
				perp_wall_dist = (hit.side_dist.y - hit.delta_dist.y);
			int line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
			draw_start = ft_clamp (-line_height / 2 + SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT - 1);
			draw_end = ft_clamp (line_height / 2 + SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT - 1);
			float wall_x;
			if (hit.side == 0)
				wall_x = game->player_pos.y + perp_wall_dist * ray_dir.y;
			else
				wall_x = game->player_pos.x + perp_wall_dist * ray_dir.x;
			wall_x -= floor (wall_x);
			int tex_x = (int)(wall_x * game->map.tex_img[0].width);
			if (hit.side == 0 && ray_dir.x > 0)
				tex_x = game->map.tex_img[0].width - tex_x - 1;
			if (hit.side == 1 && ray_dir.y < 0)
				tex_x = game->map.tex_img[0].width - tex_x - 1;
			for (int y = draw_start; y < draw_end; y += 1)
			{
				t_img	*image;
				if (hit.side == 0 && ray_dir.x > 0)
					image = &game->map.tex_img[3];
				else if (hit.side == 0 && ray_dir.x < 0)
					image = &game->map.tex_img[2];
				else if (hit.side == 1 && ray_dir.y > 0)
					image = &game->map.tex_img[1];
				else if (hit.side == 1 && ray_dir.y < 0)
					image = &game->map.tex_img[0];
				else
					image = &game->map.tex_img[hit.side];
				int tex_y = (y + line_height / 2 - SCREEN_HEIGHT / 2) * image->height / (line_height);
				tex_y = ft_clamp (tex_y, 0, image->height - 1);
				set_px(&game->frame, x, y, get_px(
					image,
					tex_x,
					tex_y
				));
			}
		}
		for (int y = 0; y < draw_start; y += 1)
			set_px (&game->frame, x, y, game->map.colors[0]);
		for (int y = draw_end; y < SCREEN_HEIGHT - 1; y += 1)
			set_px (&game->frame, x, y, game->map.colors[1]);
		x += 1;
	}
}

/*
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
		ray_dir.x = game->cam_dir.x + plane.x * (2 * x / (t_f32)SCREEN_WIDTH - 1);
		ray_dir.y = game->cam_dir.y + plane.y * (2 * x / (t_f32)SCREEN_WIDTH - 1);
		map_coord.x = (int)game->player_pos.x;
		map_coord.y = (int)game->player_pos.y;
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
				ft_panic ("Y out of bounds (%s:%i).", __FILE__, __LINE__);
			if (map_coord.x < 0 || map_coord.x >= game->map.width)
				ft_panic ("X out of bounds (%s:%i).", __FILE__, __LINE__);
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
		for (int y = 0; y < draw_start; y += 1)
		{
			set_px (&game->frame, x, y, game->map.colors[0]);
		}
		for (int y = draw_start; y < draw_end; y += 1)
		{
			t_img	image;

			if (side == 0 && ray_dir.x > 0)
				image = game->map.tex_img[3];
			else if (side == 0 && ray_dir.x < 0)
				image = game->map.tex_img[2];
			else if (side == 1 && ray_dir.y > 0)
				image = game->map.tex_img[1];
			else if (side == 1 && ray_dir.y < 0)
				image = game->map.tex_img[0];
			else
				image = game->map.tex_img[side];
			int tex_y = (y + line_height / 2 - SCREEN_HEIGHT / 2) * image.height / (line_height);
			tex_y = ft_clamp (tex_y, 0, image.height - 1);
			set_px(&game->frame, x, y, get_px(
				&image,
				tex_x,
				tex_y
			));
		}
		for (int y = draw_end; y < SCREEN_HEIGHT - 1; y += 1)
		{
			set_px (&game->frame, x, y, game->map.colors[1]);
		}
		x += 1;
	}
}
*/
