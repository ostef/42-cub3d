/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:16:45 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/18 17:37:30 by ljourand         ###   ########lyon.fr   */
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

int	tick(void *params)
{
	t_game	*game;

	game = (t_game *)params;
	update (game);
	render (game);
	mlx_put_image_to_window (game->mlx, game->mlx_win, game->frame.mlx_img, 0, 0);
	return (0);
}

t_int	main(t_int argc, t_str *args)
{
	t_game	game;

	(void)argc;
	(void)args;
	ft_memset (&game, 0, sizeof (game));
	if (!parse_map (&game.map, "data/maps/first.cub"))
		return (EXIT_FAILURE);
	init_game(&game);
	if (ft_get_heap_allocations () != 0)
		ft_fprintln (STDERR, "Found %i leaks.", ft_get_heap_allocations ());
	return (EXIT_SUCCESS);
}
