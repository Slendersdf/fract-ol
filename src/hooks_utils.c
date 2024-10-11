/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:02:41 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/11 19:05:58 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// med * 1.2 part is for the zoom
// x|y / W|H part is for the cursor pos
// So function to zoom outside from cursor pos
// by increasing the size of fractal plan
void	mouse_out(t_fractals *fractal, int x, int y)
{
	fractal->min_x = fractal->center_x - \
	fractal->med_x * (1 + 0.2) * ((double)x / WIDTH);
	fractal->max_x = fractal->center_x + \
	fractal->med_x * (1 + 0.2) * (1 - (double)x / WIDTH);
	fractal->min_y = fractal->center_y - \
	fractal->med_y * (1 + 0.2) * ((double)y / HEIGHT);
	fractal->max_y = fractal->center_y + \
	fractal->med_y * (1 + 0.2) * (1 - (double)y / HEIGHT);
}

// center_x|y are coords of the center where zoom will be done
// med * 1.2 part is for the zoom
// x|y / W|H part is for the cursor pos
// So function to zoom inside from cursor pos
// by decreasing the size of fractal plan
void	mouse_in(t_fractals *fractal, int x, int y)
{
	fractal->min_x = fractal->center_x - \
	fractal->med_x / (1 + 0.2) * ((double)x / WIDTH);
	fractal->max_x = fractal->center_x + \
	fractal->med_x / (1 + 0.2) * (1 - ((double)x / WIDTH));
	fractal->min_y = fractal->center_y - \
	fractal->med_y / (1 + 0.2) * ((double)y / HEIGHT);
	fractal->max_y = fractal->center_y + \
	fractal->med_y / (1 + 0.2) * (1 - ((double)y / HEIGHT));
}

// Function to handles moves, pretty similar concept as zoom
int	moves(int keysym, t_fractals *fractal)
{
	fractal->med_x = (fractal->max_x - fractal->min_x);
	fractal->med_y = (fractal->max_y - fractal->min_y);
	if (keysym == UP)
	{
		fractal->max_y -= fractal->med_y * 0.05;
		fractal->min_y -= fractal->med_y * 0.05;
	}
	else if (keysym == DOWN)
	{
		fractal->max_y += fractal->med_y * 0.05;
		fractal->min_y += fractal->med_y * 0.05;
	}
	else if (keysym == LEFT)
	{
		fractal->max_x -= fractal->med_x * 0.05;
		fractal->min_x -= fractal->med_x * 0.05;
	}
	else if (keysym == RIGHT)
	{
		fractal->max_x += fractal->med_x * 0.05;
		fractal->min_x += fractal->med_x * 0.05;
	}
	return (0);
}

int	change_julia(int keysym, t_fractals *fractal)
{
	if (keysym == W)
		fractal->julia_complex.real += 0.005;
	else if (keysym == S)
		fractal->julia_complex.real -= 0.005;
	else if (keysym == A)
		fractal->julia_complex.imag -= 0.005;
	else if (keysym == D)
		fractal->julia_complex.imag += 0.005;
	return (0);
}
