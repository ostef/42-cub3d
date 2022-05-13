/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:59:11 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/05 17:52:35 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_bool	init_image(t_game *game, t_image *img, int width, int height)
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

void	destroy_image(t_game *game, t_image *img)
{
	mlx_destroy_image (game->mlx, img->mlx_img);
	ft_memset (img, 0, sizeof (t_image));
}

void	set_px(t_image *img, int x, int y, t_rgba color)
{
	char	*dst;

	ft_assert (x >= 0 && x < img->width, "Invalid x (expected in [0;%d], got %d).", img->width, x);
	ft_assert (y >= 0 && y < img->height, "Invalid y (expected in [0;%d], got %d).", img->height, y);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(t_u32 *)dst = rgba_to_trgb (color);
}

t_rgba	get_px(t_image *img, int x, int y)
{
	char	*src;

	ft_assert (x >= 0 && x < img->width, "Invalid x (expected in [0;%d], got %d).", img->width, x);
	ft_assert (y >= 0 && y < img->height, "Invalid y (expected in [0;%d], got %d).", img->height, y);
	src = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (trgb_to_rgba (*(t_u32 *)src));
}

void	clear_image(t_image *img, t_rgba col)
{
	t_int	y;
	t_int	x;
	t_u32	trgb;
	char	*dst;

	trgb = rgba_to_trgb (col);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
			*(t_u32 *)dst = trgb;
			x += 1;
		}
		y += 1;
	}
}
