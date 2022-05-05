/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:52:20 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/05 16:57:18 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

typedef struct	s_ui
{
	t_uint	width;
	t_uint	height;
	t_uint	top;
	t_uint	left;
	t_str	str;
	t_rgba	bg_color;
	t_rgba	color;
}	t_ui;

void	create_ui(t_uint width, t_uint height, t_uint top, t_uint left, t_str str)
{
	
}


void	draw_ui(t_game *game, t_ui ui)
{
	
}
