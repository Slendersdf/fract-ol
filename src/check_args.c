/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:08:57 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/02 16:55:40 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_arg(void)
{
	ft_putstr_fd("Error arguments.\nusage:  Julia fractals \
	\t\t fractol [\"julia\"] (optionnal : add [real] [imag])\n\tMandelbrot fractal \
	\t fractol [\"mandelbrot\"]\n\tBurning Ship fractal \
	\t fractol [\"burningship\"]\n\tMandelbar Celtic fractal \
	 fractol [\"mandelbar\"]\n", 2);
	exit(1);
}

int	is_julia(char **argv)
{
	if (argv [1] && (ft_strncmp(argv[1], "Julia", 6) == 0 || \
	ft_strncmp(argv[1], "julia", 5) == 0))
		return (1);
	return (0);
}

int	is_mandelbrot(char **argv)
{
	if (argv[1] && (ft_strncmp(argv[1], "Mandelbrot", 10) == 0 || \
	ft_strncmp(argv[1], "mandelbrot", 10) == 0))
		return (1);
	return (0);
}

int	is_mandelbar(char **argv)
{
	if (argv[1] && (ft_strncmp(argv[1], "Mandelbar", 10) == 0 || \
	ft_strncmp(argv[1], "mandelbar", 10) == 0))
		return (1);
	return (0);
}
