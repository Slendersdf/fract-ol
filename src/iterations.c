/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:06:56 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/10 22:20:33 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// zn+1 = zn^2 + c (Julia)
// Calculate the new real par
// Initialize real and img part of dot with current coords
// Restart iteration cpt for the new point
// The loop iterates until a point diverges or max iters
// Stock temporarly real part because it will be used but modified
// Calculate the new real part with Julia formula
// Calculate the new img part with Julia formula again
// If the point (zr^2+zr^2) > 4 then it diverges so STOP!
// Diverges means the point is no part of Julia set
int	julia_iterations(t_fractals *fractal)
{
	t_complex	dot;
	double		temp;

	dot.real = fractal->x;
	dot.imag = fractal->y;
	fractal->iterations = 0;
	while (fractal->iterations < fractal->max_iterations)
	{
		temp = dot.real;
		dot.real = pow(dot.real, 2) - pow(dot.imag, 2) + \
		fractal->julia_complex.real;
		dot.imag = 2 * temp * dot.imag + fractal->julia_complex.imag;
		if (pow(dot.real, 2) + pow(dot.imag, 2) > 4.0)
			break ;
		fractal->iterations++;
	}
	return (fractal->iterations);
}

// zn+1 = zn^2 + c (Mandelbrot)
// Difference with Julia :
// Z (real and imag) start at 0 and not with pixel coord
// C is the pixel coord
int	mandelbrot_iterations(t_fractals *fractal)
{
	t_complex	dot;
	double		temp;

	dot.real = 0;
	dot.imag = 0;
	fractal->iterations = 0;
	while (fractal->iterations < fractal->max_iterations)
	{
		temp = dot.real;
		dot.real = pow(dot.real, 2) - pow(dot.imag, 2) + fractal->x;
		dot.imag = 2 * (temp * dot.imag) + fractal->y;
		if (pow(dot.real, 2) + pow(dot.imag, 2) > 4.0)
			break ;
		fractal->iterations++;
	}
	return (fractal->iterations);
}

// zn+1 = |zn^2| + c
int	mandelbar_iterations(t_fractals *fractal)
{
	t_complex	dot;
	double		temp;

	dot.real = 0;
	dot.imag = 0;
	fractal->iterations = 0;
	while (fractal->iterations < fractal->max_iterations)
	{
		temp = dot.real;
		dot.real = fabs(pow(dot.real, 2) - pow(dot.imag, 2)) + fractal->x;
		dot.imag = -2 * temp * dot.imag + fractal->y;
		if (pow(dot.real, 2) + pow(dot.imag, 2) > 4.0)
			break ;
		fractal->iterations++;
	}
	return (fractal->iterations);
}
