/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:46:45 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/02 15:46:52 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_s64	parse_data(t_map *map, t_cstr str)
{
	t_s64	i;
	t_s64	adv;
	t_s64	x;
	t_s64	y;

	i = 0;
	while (str[i] && str[i] == '\n')
		i += 1;
	while (str[i])
	{
		adv = skip_until_newline (str + i);
		if (adv == 0)
			return (eprint ("Found empty line in map description."));
		i += adv;
		if (str[i] == '\n')
			i += 1;
		map->width = ft_max (map->width, adv);
		map->height += 1;
	}
	map->data = (char *)ft_alloc (map->width * map->height, ft_heap ());
	i = 0;
	while (str[i] && str[i] == '\n')
		i += 1;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (str[i] && str[i] != '\n')
			{
				map->data[y * map->width + x] = str[i];
				i += 1;
			}
			else
				map->data[y * map->width + x] = ' ';
			x += 1;
		}
		i += skip_until_newline (str + i);
		if (str[i] == '\n')
			i += 1;
		y += 1;
	}
	return (i);
}
