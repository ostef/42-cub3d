/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:59:11 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/05 17:55:43 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_image(t_game *game, t_image *img, int width, int height)
{
	img->mlx_img = mlx_new_image (game->mlx, width, height);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr (img->mlx_img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
}

void	init_image_xpm(t_game *game, t_image *img, t_str filename)
{
	int	width;
	int	height;
	
	img->mlx_img = mlx_xpm_file_to_image(game->mlx, filename, &width, &height);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr (img->mlx_img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
}

void	set_px(t_image *img, int x, int y, t_rgba color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(t_u32 *)dst = rgba_to_trgb (color);
}

t_rgba	get_px(t_image *img, int x, int y)
{
	char	*src;

	src = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (trgb_to_rgba (*(t_u32 *)src));
}

