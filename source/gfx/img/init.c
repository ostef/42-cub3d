/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:10:56 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/17 16:55:04 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_bool	init_img(t_game *game, t_img *img, int width, int height)
{
	img->mlx_img = mlx_new_image (game->mlx, width, height);
	if (!img->mlx_img)
		return (FALSE);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr (img->mlx_img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	return (TRUE);
}

t_bool	init_img_xpm(t_game *game, t_img *img, t_str filename)
{
	int	width;
	int	height;
	
	img->mlx_img = mlx_xpm_file_to_image(game->mlx, filename, &width, &height);
	if (!img->mlx_img)
		return (FALSE);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr (img->mlx_img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	return (TRUE);
}

void	destroy_img(t_game *game, t_img *img)
{
	mlx_destroy_image (game->mlx, img->mlx_img);
	ft_memset (img, 0, sizeof (t_img));
}
