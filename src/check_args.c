/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:08:57 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/11 19:23:21 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	if_julia(char **argv)
{
	if (argv [1] && (ft_strncmp(argv[1], "julia\0", 6) == 0 || \
	ft_strncmp(argv[1], "Julia\0", 6) == 0))
		return (1);
	return (0);
}

int	if_mandelbrot(char **argv)
{
	if (argv[1] && (ft_strncmp(argv[1], "mandelbrot\0", 11) == 0 || \
	ft_strncmp(argv[1], "Mandelbrot\0", 11) == 0))
		return (1);
	return (0);
}

int	if_mandelbar(char **argv)
{
	if (argv[1] && (ft_strncmp(argv[1], "mandelbar\0", 11) == 0 || \
	ft_strncmp(argv[1], "Mandelbar\0", 11) == 0))
		return (1);
	return (0);
}

void	error_arg(void)
{
	ft_putstr_fd("Wrong arguments.\nCorrect format:  Julia fractals \
	\t\t fractol [\"julia\"] (optionnal : add [real] [imag])\n\tMandelbrot fractal \
	\t fractol [\"mandelbrot\"]\n\tMandelbar Celtic fractal \
	 fractol [\"mandelbar\"]\n", 2);
	exit(1);
}

int	error_julia(int argc, char **argv)
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
