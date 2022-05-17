/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:11:30 by soumanso          #+#    #+#             */
/*   Updated: 2022/05/17 16:55:01 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	set_px(t_img *img, int x, int y, t_rgba color)
{
	char	*dst;

	ft_assert (x >= 0 && x < img->width, "Invalid x (expected in [0;%d], got %d).", img->width, x);
	ft_assert (y >= 0 && y < img->height, "Invalid y (expected in [0;%d], got %d).", img->height, y);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(t_u32 *)dst = rgba_to_trgb (color);
}

t_rgba	get_px(t_img *img, int x, int y)
{
	char	*src;

	ft_assert (x >= 0 && x < img->width, "Invalid x (expected in [0;%d], got %d).", img->width, x);
	ft_assert (y >= 0 && y < img->height, "Invalid y (expected in [0;%d], got %d).", img->height, y);
	src = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (trgb_to_rgba (*(t_u32 *)src));
}

void	clear_img(t_img *img, t_rgba col)
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
