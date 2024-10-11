/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:56:34 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/11 19:23:14 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	color_set(int keysym, t_fractals *fractal)
{
	if (keysym == NUM_1)
		fractal->color_rb--;
	else if (keysym == NUM_2)
		fractal->color_rb++;
	else if (keysym == NUM_4)
		fractal->color_gpi--;
	else if (keysym == NUM_5)
		fractal->color_gpi++;
	else if (keysym == NUM_7)
		fractal->color_ypu--;
	else if (keysym == NUM_8)
		fractal->color_ypu++;
	else if (keysym == NUM_0)
	{
		fractal->color_rb = 12;
		fractal->color_gpi = 11;
		fractal->color_ypu = 15;
	}
	return (0);
}

int	destroy(t_fractals *fractal)
{
	mlx_destroy_image(fractal->img.mlx_ptr, fractal->img.img);
	mlx_destroy_window(fractal->img.mlx_ptr, fractal->img.mlx_win);
	mlx_destroy_display(fractal->img.mlx_ptr);
	free(fractal->img.mlx_ptr);
	exit(0);
}

// Function that puts a pixel of a specific color
// at a given position (x, y)
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
