/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:57:25 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/11 19:27:30 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include <limits.h>

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define MOUSE_IN 4
# define MOUSE_OUT 5

# define NUM_1 65436
# define NUM_2 65433
# define NUM_3 65435
# define NUM_4 65430
# define NUM_5 65437
# define NUM_6 65432
# define NUM_7 65429
# define NUM_8 65431
# define NUM_0 65438

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_img {
	void	*img;
	char	*addr;
	void	*mlx_ptr;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_complex {
	double	real;
	double	imag;
}			t_complex;

typedef struct s_fractals {
	int					iterations;
	int					max_iterations;
	int					color_rb;
	int					color_gpi;
	int					color_ypu;
	double				center_x;
	double				center_y;
	double				x;
	double				y;
	double				min_x;
	double				max_x;
	double				min_y;
	double				max_y;
	double				med_x;
	double				med_y;
	struct s_img		img;
	struct s_complex	julia_complex;
	int					(*fract)(struct s_fractals *fractal);
}						t_fractals;

//check_args.c
int			if_julia(char **argv);
int			if_mandelbrot(char **argv);
int			if_mandelbar(char **argv);
void		error_arg(void);
int			error_julia(int argc, char **argv);
//draw.c
int			choose_fractal(int argc, char **argv, t_fractals *fractal);
int			draw_fractal(t_fractals *fractal);
int			pretty_color(t_fractals *fractal);
//hooks_main.c
int			handle_input(int keysym, t_fractals *fractal);
int			handle_mouse(int event, int x, int y, t_fractals *fractal);
//hooks_utils.c
void		mouse_out(t_fractals *fractal, int x, int y);
void		mouse_in(t_fractals *fractal, int x, int y);
int			moves(int keysym, t_fractals *fractal);
int			change_julia(int keysym, t_fractals *fractal);
//iterations.c
int			julia_iters(t_fractals *fractal);
int			mandelbrot_iters(t_fractals *fractal);
int			mandelbar_iters(t_fractals *fractal);
//main.c
void		init_fract(int argc, char **argv, t_fractals *fractal);
void		init_img(t_fractals *fractal);
void		init_julia_val(int argc, char **argv, t_fractals *fractal);
//utils.c
int			color_set(int keysym, t_fractals *fractal);
int			destroy(t_fractals *fractal);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
