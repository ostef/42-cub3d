/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:02:29 by ljourand          #+#    #+#             */
/*   Updated: 2022/05/23 14:21:36 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	destroy(int keycode, void *null)
{
	if (ft_get_heap_allocations () != 0)
		ft_fprintln (STDERR, "Found %i leaks.", ft_get_heap_allocations ());
	exit(0);
	(void)keycode;
	(void)null;
	return (0);
}

void	init_keys(t_game *game)
{
	t_keys	*keys;

	keys = &game->keys;
	keys->keys[FORWARD] = KEY_UP;
	keys->keys[BACKWARD] = KEY_DOWN;
	keys->keys[LEFT] = KEY_LEFT;
	keys->keys[RIGHT] = KEY_RIGHT;
	keys->keys[SHOOT] = KEY_CTRL;
	keys->change_key = NO_CHANGE;
}

void	get_player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			game->player_pos.x = x;
			game->player_pos.y = y;
			if (game->map.data[y * game->map.width + x] == 'N')
			{
				game->cam_dir.x = 0;
				game->cam_dir.y = 1;
				return ;
			}
			else if (game->map.data[y * game->map.width + x] == 'W')
			{
				game->cam_dir.x = -1;
				game->cam_dir.y = 0;
				return ;
			}
			else if (game->map.data[y * game->map.width + x] == 'S')
			{
				game->cam_dir.x = 0;
				game->cam_dir.y = -1;
				return ;
			}
			else if (game->map.data[y * game->map.width + x] == 'E')
			{
				game->cam_dir.x = 1;
				game->cam_dir.y = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_game(t_game *game)
{
	int	i;

	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Cube3d");
	if (!init_img (game, &game->frame, SCREEN_WIDTH, SCREEN_HEIGHT))
		ft_panic ("Could not initialize framebuffer.");
	i = 0;
	while (i < 4)
	{
		if (!init_img_xpm(game, &(game->map.tex_img[i]),
				game->map.tex_names[i]))
		{
			printf("error texture: %s\n", game->map.tex_names[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_memset(&game->params, 0, sizeof(t_param));
	init_font(game);
	init_keys(game);
	create_panels(game);
	mlx_hook(game->mlx_win, MOUSE_PRESS, 0L, mouse_press, game);
	mlx_hook(game->mlx_win, MOUSE_RELEASE, 0L, mouse_release, game);
	mlx_hook(game->mlx_win, MOUSE_MOVE, 0L, mouse_move, game);
	mlx_hook(game->mlx_win, KEY_PRESS, 0L, keydown, game);
	mlx_hook(game->mlx_win, KEY_RELEASE, 0L, keyup, game);
	mlx_hook(game->mlx_win, DESTROY_NOTIFY, 0L, destroy, NULL);
	get_player_pos(game);
	mlx_loop_hook(game->mlx, tick, game);
	mlx_loop(game->mlx);
}
