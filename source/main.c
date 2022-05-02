/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:16:45 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/02 17:39:54 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_int	main(t_int argc, t_str *args)
{
	t_int	i;
	t_game	game;

	ft_println ("Hello Sailor!");
	i = 0;
	while (i < argc)
	{
		ft_println (args[i]);
		i += 1;
	}
	init_game(&game);
}
