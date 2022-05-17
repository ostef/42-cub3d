/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:41:07 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/17 16:54:47 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_vec2f	vec2f_add(t_vec2f lhs, t_vec2f rhs)
{
	return (vec2f (lhs.x + rhs.x, lhs.y + rhs.y));
}

t_vec2f	vec2f_sub(t_vec2f lhs, t_vec2f rhs)
{
	return (vec2f (lhs.x - rhs.x, lhs.y - rhs.y));
}

t_vec2f	vec2f_neg(t_vec2f v)
{
	return (vec2f (-v.x, -v.y));
}

t_vec2f	vec2f_mul(t_vec2f v, t_f32 s)
{
	return (vec2f (v.x * s, v.y * s));
}

t_vec2f	vec2f_div(t_vec2f v, t_f32 s)
{
	return (vec2f (v.x / s, v.y / s));
}
