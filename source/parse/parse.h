/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:43:54 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/02 15:47:00 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cube.h"

t_s64	skip_spaces(t_cstr str);
t_s64	skip_until_newline(t_cstr str);

t_s64	parse_tex_names(t_map *map, t_cstr str);
t_s64	parse_colors(t_map *map, t_cstr str);
t_s64	parse_data(t_map *map, t_cstr str);

#endif
