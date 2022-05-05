/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:03:38 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/03 16:10:50 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_u32	rgba_to_trgb(t_rgba x)
{
	t_u32	res;

	res =  ((255 - x.r) << 24) | (x.r << 16) | (x.g << 8) | (x.b);
	return (res);
}

t_rgba	trgb_to_rgba(t_u32 x)
{
	t_rgba	res;

	res.a = 255 - ((x >> 24) & 0xff);
	res.r = (x >> 16) & 0xff;
	res.g = (x >> 8) & 0xff;
	res.b = (x) & 0xff;
	return (res);
}
