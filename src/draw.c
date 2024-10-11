/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:08:14 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/11 19:32:20 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	choose_fractal(int argc, char **argv, t_fractals *fractal)
{
	if (if_mandelbrot(argv))
	{
		if (argc == 2)
			fractal->fract = mandelbrot_iters;
	}
	if (if_julia(argv))
	{
		fractal->fract = julia_iters;
		init_julia_val(argc, argv, fractal);
	}
	if (if_mandelbar(argv))
	{
		if (argc == 2)
			fractal->fract = mandelbar_iters;
	}
	return (0);
}

// Function that transform the coordinates of the pixels from image
// to true coordinates of fractal plan used by iterations functions
// Then we apply the corresponding color to the pixel and
// we display the entier image at the end
int	draw_fractal(t_fractals *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractal->x = fractal->min_x + (fractal->max_x - \
			fractal->min_x) * x / (WIDTH);
			fractal->y = fractal->min_y + (fractal->max_y - \
			fractal->min_y) * y / (HEIGHT);
			fractal->fract(fractal);
			my_mlx_pixel_put(&fractal->img, x, y, pretty_color(fractal));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->img.mlx_ptr, fractal->img.mlx_win, \
	fractal->img.img, fractal->min_x, fractal->min_y);
	return (0);
}

// Function that calculates a color for a given iterations number value
// (specific to each fractal)
// If iteration value = max iteration then we are inside the set of the fractal
// (so a black color)
// The three following lines calculates the values of red, blue and green
// sin(0.3 * iter + shift) creates a periodic oscilation
// It changes colors values and makes it like a fluid degraded colors
// rb|gpi|ypu are shifting value for (red, green and blue)
// that changes the tones of colors
// 125 just to have a bigger variation of color
// and 126 to get valid values for RGB components
// Last line is just a combination of the three colors components
// to get a 24 RGB bits standard
// First strong bits of red, next green's one and lastly blue's one (RGB order)
int	pretty_color(t_fractals *fractal)
{
	int	rgb[3];

	if (fractal->iterations == fractal->max_iterations)
		return (0x00111111);
	rgb[0] = sin(0.3 * fractal->iterations + fractal->color_rb) * 125 + 126;
	rgb[1] = sin(0.3 * fractal->iterations + fractal->color_gpi) * 125 + 126;
	rgb[2] = sin(0.3 * fractal->iterations + fractal->color_ypu) * 125 + 126;
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
