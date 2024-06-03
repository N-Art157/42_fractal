/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:37:19 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/02 04:47:24 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include "fractol.h"
#include <stdio.h>

void	init_fractal(t_fractal *fractal, int width, int height)
{
	fractal -> min_re = -2.0;
	fractal -> max_re = 1.0;
	fractal -> min_im = -1.5;
	fractal -> max_im = 1.5/*(*fractal).min_im + ((*fractal).max_re - (*fractal).min_re) * height / width*/;
	fractal -> re_factor = ((*fractal).max_re - (*fractal).min_re) / (width - 1);
	fractal -> im_factor = ((*fractal).max_im - (*fractal).min_im) / (height - 1);
}

int	compute_fractal(t_complex z, t_complex c)
{
	int 	n;
	int 	max_iter;
	double	z_re2;
	double	z_im2;

	max_iter = 50;
	n = 0;
	while (n < max_iter)
	{
		z_re2 = z.re * z.re ;
		z_im2 = z.im * z.im;
		if (z_re2 + z_im2 > 4)
		{
			n = (n * 255 / max_iter) << 8;
			return (n);
		}
		z.im = 2 * z.re * z.im + c.im;
		z.re = z_re2 - z_im2 + c.re;
		n++;
	}
	return (0x000000);
}

void	draw_mandelbrot(t_data	*img, int width, int height)
{
	t_fractal fractal;
	t_complex c;
	t_complex z;
	int	x;
	int	y;

	printf("%f\n",img -> ratio);
	init_fractal(&fractal, width, height);
	y = 0;
	while (height > y)
	{
		x = 0;
		while (width > x)
		{
			c.re = fractal.min_re + x * fractal.re_factor * img -> ratio;
			c.im = fractal.max_im - y * fractal.im_factor * img -> ratio;
			z.re = 0;
			z.im = 0;
			my_mlx_pixel_put(img, x, y, compute_fractal(z,c));
			x++;
		}
		y++;
	}
}


