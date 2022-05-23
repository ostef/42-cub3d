/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:45:13 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/23 14:22:28 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static const t_cstr	g_dirs[] = {"NO", "SO", "WE", "EA"};

t_s64	parse_tex_names(t_map *map, t_cstr str)
{
	t_int	dir;
	t_s64	i;
	t_pcstr	name;

	i = 0;
	dir = 0;
	while (dir < 4 && str[i])
	{
		while (str[i] && str[i] == '\n')
			i += 1;
		if (!ft_strnequ (str + i, g_dirs[dir], ft_strlen (g_dirs[dir])))
			return (eprint ("Expected '%s', got\n%s.", g_dirs[dir], str + i));
		i += ft_strlen (g_dirs[dir]);
		if (str[i] == '\n' || !ft_is_space (str[i]))
			return (eprint ("Expected a whitespace after '%s'.", g_dirs[dir]));
		i += skip_spaces (str + i);
		name.data = str + i;
		while (str[i] && !ft_is_space (str[i]))
			i += 1;
		name.len = str + i - name.data;
		i += skip_spaces (str + i);
		if (str[i] != '\n')
			return (eprint ("Expected a newline after texture name."));
		map->tex_names[dir] = ft_strndup (name.data, name.len, ft_heap ());
		dir += 1;
	}
	return (i);
}
