/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:16:45 by soumanso          #+#    #+#             */
/*   Updated: 2022/04/29 16:20:54 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_int	main(t_int argc, t_str *args)
{
	t_int	i;

	ft_println ("Hello Sailor!");
	i = 0;
	while (i < argc)
	{
		ft_println (args[i]);
		i += 1;
	}
}
