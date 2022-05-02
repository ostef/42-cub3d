/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:16:45 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/02 15:49:14 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_bool	eprint(t_cstr fmt, ...)
{
	va_list	va;

	ft_fprintln (STDERR, "Error");
	va_start (va, fmt);
	ft_vfprintln (STDERR, fmt, va);
	va_end (va);
	return (FALSE);
}

t_int	main(t_int argc, t_str *args)
{
	t_map	map;

	if (!parse_map (&map, "data/maps/first.cub"))
		return (EXIT_FAILURE);
	ft_println ("NO '%s'", map.tex_names[0]);
	ft_println ("SO '%s'", map.tex_names[1]);
	ft_println ("WE '%s'", map.tex_names[2]);
	ft_println ("EA '%s'", map.tex_names[3]);
	ft_println ("F %u,%u,%u", map.colors[0].r, map.colors[0].g, map.colors[0].b);
	ft_println ("C %u,%u,%u", map.colors[1].r, map.colors[1].g, map.colors[1].b);
	for (int y = 0; y < map.height; y += 1)
	{
		for (int x = 0; x < map.width; x += 1)
		{
			ft_print ("%c", map.data[y * map.width + x]);
		}
		ft_print ("\n");
	}
	(void)argc;
	(void)args;
	if (ft_get_heap_allocations () != 0)
		ft_fprintln (STDERR, "Found %i leaks.", ft_get_heap_allocations ());
	return (EXIT_SUCCESS);
}
