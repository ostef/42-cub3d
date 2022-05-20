/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:44:58 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/20 15:00:53 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_f32	vec2f_dot(t_vec2f a, t_vec2f b)
{
	return (a.x * b.x + a.y * b.y);
}

t_vec2f	vec2f_perp_cw(t_vec2f v)
{
	return (vec2f (v.y, -v.x));
}

t_vec2f	vec2f_perp_ccw(t_vec2f v)
{
	return (vec2f (-v.y, v.x));
}

t_f32	vec2f_len(t_vec2f v)
{
	return (sqrtf (v.x * v.x + v.y * v.y));
}

t_vec2f	vec2f_normalized(t_vec2f v)
{
	t_f32	len;

	len = vec2f_len (v);
	if (len == 0)
		return (vec2f (0, 0));
	return (vec2f (v.x / len, v.y / len));
}
