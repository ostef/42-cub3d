/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:17:14 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/02 15:06:42 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "libft.h"
# include "mlx.h"

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

/* A t_map has all the information that is in a .cub file, in a somewhat
 * structured manner. This is not the in-game map that you see on screen,
 * where you have ennemies and stuff running around. */

typedef struct s_map
{
	t_str	tex_names[4];
	t_rgba	colors[2];
	t_int	width;
	t_int	height;
	char	*data;
}	t_map;

t_bool	eprint(t_cstr fmt, ...);
t_bool	parse_map(t_map *map, t_cstr filename);

#endif
