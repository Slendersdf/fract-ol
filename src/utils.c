/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:56:34 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/03 14:23:38 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	color_set(int keysym, t_fractals *fractal)
{
	if (keysym == PAD_1)
		fractal->color_rb--;
	else if (keysym == PAD_2)
		fractal->color_rb++;
	else if (keysym == PAD_4)
		fractal->color_gpi--;
	else if (keysym == PAD_5)
		fractal->color_gpi++;
	else if (keysym == PAD_7)
		fractal->color_ypu--;
	else if (keysym == PAD_8)
		fractal->color_ypu++;
	else if (keysym == PAD_0)
	{
		fractal->color_rb = 12;
		fractal->color_gpi = 11;
		fractal->color_ypu = 15;
	}
	return (0);
}

void	mouse_down(t_fractals *fractal, int x, int y)
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

void	mouse_up(t_fractals *fractal, int x, int y)
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

int	ft_error_julia(int argc, char **argv)
{
	double	value1;
	double	value2;

	if (argc != 2 && argc != 4)
		return (0);
	if (argc == 4)
	{
		if ((ft_strlen(argv[2]) > 11 || ft_strlen(argv[3]) > 11))
			return (0);
		if (!(ft_isalldigits(argv[2]) && ft_isalldigits(argv[3])))
			return (0);
		else
		{
			value1 = ft_atod(argv[2]);
			value2 = ft_atod(argv[3]);
			if (!(value1 >= INT_MIN && value1 <= INT_MAX) || \
			!(value2 >= INT_MIN && value2 <= INT_MAX))
				return (0);
		}
	}
	return (1);
}
