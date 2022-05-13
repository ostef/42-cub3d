/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_math.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:41:36 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/13 13:44:42 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_MATH_H
# define CUBE_MATH_H

# include "libft.h"

typedef union u_rgba
{
	struct
	{
		t_u8	r;
		t_u8	g;
		t_u8	b;
		t_u8	a;
	};
	t_u8		n[4];
}	t_rgba;

t_rgba	rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a);
t_u32	rgba_to_trgb(t_rgba x);
t_rgba	trgb_to_rgba(t_u32 x);

typedef union u_vec2f
{
	t_f32		n[2];
	struct
	{
		t_f32	x;
		t_f32	y;
	};
}	t_vec2f;

t_vec2f	vec2f(t_f32 x, t_f32 y);
t_vec2f	vec2f_add(t_vec2f lhs, t_vec2f rhs);
t_vec2f	vec2f_sub(t_vec2f lhs, t_vec2f rhs);
t_vec2f	vec2f_neg(t_vec2f v);
t_vec2f	vec2f_mul(t_vec2f v, t_f32 s);
t_vec2f	vec2f_div(t_vec2f v, t_f32 s);
t_f32	vec2f_dot(t_vec2f a, t_vec2f b);
t_vec2f	vec2f_perp_cw(t_vec2f v);
t_vec2f	vec2f_perp_ccw(t_vec2f v);

#endif
