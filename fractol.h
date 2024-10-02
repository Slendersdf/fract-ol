/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:57:25 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/02 16:15:27 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define PAD_1 65436
# define PAD_2 65433
# define PAD_3 65435
# define PAD_4 65430
# define PAD_5 65437
# define PAD_6 65432
# define PAD_7 65429
# define PAD_8 65431
# define PAD_9 65434
# define PAD_0 65438

# define WIDTH 1920
# define HEIGHT 1080
# define ZOOM_FACTOR 1.15

typedef struct s_complex {
	double	real;
	double	imag;
}			t_complex;

typedef struct s_img {
	void	*img;
	char	*addr;
	void	*mlx_ptr;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

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

// Img and init
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		init_fract(int argc, char **argv, t_fractals *fractal);
void		init_img(t_fractals *fractal);
void		init_julia_val(int argc, char **argv, t_fractals *fractal);

//	Fractals
int			pick_fractal(int argc, char **argv, t_fractals *fractal);

	// Calculate
int			julia_iterations(t_fractals *fractal);
int			mandelbrot_iterations(t_fractals *fractal);
int			burning_ship_iterations(t_fractals *fractal);
int			mandelbar_iterations(t_fractals *fractal);

	// Draw
int			draw_fractal(t_fractals *fractal);
int			ft_color(t_fractals *fractal);

//	Events
int			handle_input(int keysym, t_fractals *fractal);
void		mouse_down(t_fractals *fractal, int x, int y);
void		mouse_up(t_fractals *fractal, int x, int y);
int			handle_mouse(int event, int x, int y, t_fractals *fractal);
int			destroy_and_free(t_fractals *fractal);
int			moves(int keysym, t_fractals *fractal);
int			change_julia(int keysym, t_fractals *fractal);

//	Checks
void		ft_error_arg(void);
int			ft_error_julia(int argc, char **argv);
int			is_julia(char **argv);
int			is_mandelbrot(char **argv);
int			is_burningship(char **argv);
int			is_mandelbar(char **argv);

// Utils
void		ft_fractol_man(void);
int			color_set(int keysym, t_fractals *fractal);

#endif
