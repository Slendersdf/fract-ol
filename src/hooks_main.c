/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:05:31 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/11 19:12:52 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_input(int keysym, t_fractals *fractal)
{
	if (keysym == ESC)
	{
		destroy(fractal);
		exit(0);
	}
	else if (keysym == NUM_6 && fractal->max_iterations < 800)
		fractal->max_iterations += 50;
	else if (keysym == NUM_3 && fractal->max_iterations > 50)
		fractal->max_iterations -= 50;
	moves(keysym, fractal);
	change_julia(keysym, fractal);
	color_set(keysym, fractal);
	draw_fractal(fractal);
	return (0);
}

int	handle_mouse(int event, int x, int y, t_fractals *fractal)
{
	fractal->med_x = (fractal->max_x - fractal->min_x);
	fractal->med_y = (fractal->max_y - fractal->min_y);
	fractal->center_x = fractal->min_x + ((double)x / WIDTH) * fractal->med_x;
	fractal->center_y = fractal->min_y + ((double)y / HEIGHT) * fractal->med_y;
	if (event == MOUSE_OUT)
		mouse_out(fractal, x, y);
	else if (event == MOUSE_IN)
		mouse_in(fractal, x, y);
	draw_fractal(fractal);
	return (0);
}
