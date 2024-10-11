/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:57:08 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/11 19:28:31 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Function that initializes the structure t_fractals,
// which contains all the necessary informations
// to calculate and display a fractal
void	init_fract(int argc, char **argv, t_fractals *fractal)
{
	fractal->max_iterations = 50;
	fractal->color_rb = 12;
	fractal->color_gpi = 11;
	fractal->color_ypu = 15;
	choose_fractal(argc, argv, fractal);
	fractal->min_x = -2.5;
	fractal->max_x = 2.5;
	fractal->min_y = -2.0;
	fractal->max_y = 2.0;
	fractal->med_x = (fractal->max_x - fractal->min_x);
	fractal->med_y = (fractal->max_y - fractal->min_y);
}

// Function that initalises the complexe values for Julia
void	init_julia_val(int argc, char **argv, t_fractals *fractal)
{
	if (argc == 4 && (ft_isalldigits(argv[2]) && ft_isalldigits(argv[3])))
	{
		fractal->julia_complex.real = ft_atod(argv[2]);
		fractal->julia_complex.imag = ft_atod(argv[3]);
	}
	else if (argc == 2)
	{
		fractal->julia_complex.real = -1;
		fractal->julia_complex.imag = 0;
	}
}

// Function that initialises the image with mlx
void	init_img(t_fractals *fractal)
{
	fractal->img.mlx_ptr = mlx_init();
	if (fractal->img.mlx_ptr == NULL)
		ft_error();
	fractal->img.mlx_win = mlx_new_window(fractal->img.mlx_ptr, \
	WIDTH, HEIGHT, "Pour Meiling");
	if (fractal->img.mlx_win == NULL)
	{
		free(fractal->img.mlx_ptr);
		ft_error();
	}
	fractal->img.img = mlx_new_image(fractal->img.mlx_ptr, WIDTH, HEIGHT);
	{
		if (fractal->img.img == NULL)
		{
			free(fractal->img.mlx_win);
			free(fractal->img.mlx_ptr);
			ft_error();
		}
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, \
	&fractal->img.bits_per_pixel, &fractal->img.line_length, \
	&fractal->img.endian);
}

int	main(int argc, char **argv)
{
	t_fractals	fractal;

	if (if_julia(argv) && !(error_julia(argc, argv)))
		error_arg();
	else if ((if_mandelbrot(argv) || if_mandelbar(argv)) && (argc != 2))
		error_arg();
	if (!if_julia(argv) && !if_mandelbrot(argv) && \
	!if_mandelbar(argv))
		error_arg();
	else
	{
		init_fract(argc, argv, &fractal);
		init_img(&fractal);
		mlx_mouse_hook(fractal.img.mlx_win, &handle_mouse, &fractal);
		mlx_key_hook(fractal.img.mlx_win, &handle_input, &fractal);
		mlx_hook(fractal.img.mlx_win, 17, 1L << 17, \
		&destroy, &fractal);
		draw_fractal(&fractal);
		mlx_expose_hook(fractal.img.mlx_win, draw_fractal, &fractal);
		mlx_loop(fractal.img.mlx_ptr);
	}
	return (0);
}
