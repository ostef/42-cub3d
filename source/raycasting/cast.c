/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:20:13 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/20 17:14:00 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_hit	raycast(t_game *game, t_vec2f orig, t_vec2f dir, t_f32 len)
{
	t_hit	res;
	t_coord	step;

	ft_memset (&res, 0, sizeof (t_hit));
	if (fabs (dir.x) < 0.0001 && fabs (dir.x) < 0.0001)
		return (res);
	res.coord.x = (int)orig.x;
	res.coord.y = (int)orig.y;
	res.delta_dist.x = ft_absf (1 / dir.x);
	res.delta_dist.y = ft_absf (1 / dir.y);
	if (dir.x < 0)
	{
		step.x = -1;
		res.side_dist.x = (orig.x - res.coord.x) * res.delta_dist.x;
	}
	else
	{
		step.x = 1;
		res.side_dist.x = (res.coord.x + 1 - orig.x) * res.delta_dist.x;
	}
	if (dir.y < 0)
	{
		step.y = -1;
		res.side_dist.y = (orig.y - res.coord.y) * res.delta_dist.y;
	}
	else
	{
		step.y = 1;
		res.side_dist.y = (res.coord.y + 1 - orig.y) * res.delta_dist.y;
	}
	while (TRUE)
	{
		if (res.side_dist.x < res.side_dist.y)
		{
			res.side_dist.x += res.delta_dist.x;
			res.coord.x += step.x;
			res.side = 0;
		}
		else
		{
			res.side_dist.y += res.delta_dist.y;
			res.coord.y += step.y;
			res.side = 1;
		}
		if (vec2f_dot (res.side_dist, res.side_dist) > len * len)
			return (res);
		if (res.coord.y < 0 || res.coord.y >= game->map.height)
			ft_panic ("Y out of bounds (%s:%i).", __FILE__, __LINE__);
		if (res.coord.x < 0 || res.coord.x >= game->map.width)
			ft_panic ("X out of bounds (%s:%i).", __FILE__, __LINE__);
		if (game->map.data[res.coord.y * game->map.width + res.coord.x] == '1')
			break ;
	}
	res.hit = TRUE;
	res.dir = dir;
	return (res);
}
