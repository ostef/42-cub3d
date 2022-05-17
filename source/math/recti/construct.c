/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:18:51 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/17 16:54:54 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_recti	recti(t_int x, t_int y, t_int w, t_int h)
{
	t_recti	r;

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return (r);
}
