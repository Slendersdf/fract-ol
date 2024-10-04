/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:08:57 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/03 20:52:38 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_error_arg(void)
{
	ft_putstr_fd("Wrong arguments.\nCorrect format:  Julia fractals \
	\t\t fractol [\"julia\"] (optionnal : add [real] [imag])\n\tMandelbrot fractal \
	\t fractol [\"mandelbrot\"]\n\tMandelbar Celtic fractal \
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
