/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:45:38 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/23 14:20:50 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static const t_cstr	g_cols[] = {"F", "C"};

static t_s64	parse_color(t_map *map, t_cstr str, t_int col_i)
{
	t_s64	i;
	t_s64	adv;
	t_uint	temp;

	i = 0;
	adv = ft_str_to_uint (str + i, &temp);
	if (!adv)
		return (eprint ("Expected a uint value for R."));
	i += adv;
	if (temp > 255)
		return (eprint ("R is outside of the range [0,255]."));
	if (str[i] != ',')
		return (eprint ("Expected a comma after R value."));
	i += 1;
	map->colors[col_i].r = (t_u8)temp;
	adv = ft_str_to_uint (str + i, &temp);
	if (!adv)
		return (eprint ("Expected a uint value for G."));
	i += adv;
	if (temp > 255)
		return (eprint ("G is outside of the range [0,255]."));
	if (str[i] != ',')
		return (eprint ("Expected a comma after G value."));
	i += 1;
	map->colors[col_i].g = (t_u8)temp;
	adv = ft_str_to_uint (str + i, &temp);
	if (!adv)
		return (eprint ("Expected a uint value for B."));
	i += adv;
	if (temp > 255)
		return (eprint ("G is outside of the range [0,255]."));
	map->colors[col_i].b = (t_u8)temp;
	map->colors[col_i].a = 255;
	return (i);
}

t_s64	parse_colors(t_map *map, t_cstr str)
{
	t_s64	i;
	t_s64	adv;
	t_int	col;

	i = 0;
	col = 0;
	while (col < 2 && str[i])
	{
		while (str[i] && str[i] == '\n')
			i += 1;
		if (!ft_strnequ (str + i, g_cols[col], ft_strlen (g_cols[col])))
			return (eprint ("Expected '%s', got\n%s.", g_cols[col], str + i));
		i += ft_strlen (g_cols[col]);
		if (str[i] == '\n' || !ft_is_space (str[i]))
			return (eprint ("Expected a whitespace after '%s'.", g_cols[col]));
		i += skip_spaces (str + i);
		adv = parse_color (map, str + i, col);
		if (!adv)
			return (FALSE);
		i += adv;
		i += skip_spaces (str + i);
		if (str[i] != '\n')
			return (eprint ("Expected a newline after R,G,B."));
		col += 1;
	}
	return (i);
}
