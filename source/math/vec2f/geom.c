/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:44:58 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/17 16:54:43 by soumanso         ###   ########lyon.fr   */
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
