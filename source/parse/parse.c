/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:02:18 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/02 15:49:03 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_bool	parse_map(t_map *map, t_cstr filename)
{
	t_str	file_contents;
	t_s64	i;
	t_s64	adv;

	ft_memset (map, 0, sizeof (*map));
	file_contents = ft_read_entire_file (filename, ft_heap ());
	if (!file_contents)
		return (eprint ("Could not read file '%s'.", filename));
	i = 0;
	adv = parse_tex_names (map, file_contents + i);
	if (!adv)
	{
		ft_free (file_contents, ft_heap ());
		return (eprint ("Could not parse texture names."));
	}
	i += adv;
	adv = parse_colors (map, file_contents + i);
	if (!adv)
	{
		ft_free (file_contents, ft_heap ());
		return (eprint ("Could not parse colors."));
	}
	i += adv;
	adv = parse_data (map, file_contents + i);
	if (!adv)
	{
		ft_free (file_contents, ft_heap ());
		return (eprint ("Could not parse map description."));
	}
	i += adv;
	ft_free (file_contents, ft_heap ());
	return (TRUE);
}
