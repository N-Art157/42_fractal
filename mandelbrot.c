/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:37:19 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/10 13:51:10 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_data *data, int width, int height)
{
	if (data -> sign == 2)
	{
		data -> fractal.min_re = 0;
		data -> fractal.max_re = width;
		data -> fractal.min_im = 0;
		data -> fractal.min_re = height;
		data -> fractal.re_factor = 1;
		data -> fractal.im_factor = 1;
	}
	else
	{
		data -> fractal.min_re = -2.0;
		data -> fractal.max_re = 1.0;
		data -> fractal.min_im = -1.5;
		data -> fractal.max_im = 1.5/*(*fractal).min_im + ((*fractal).max_re - (*fractal).min_re) * height / width*/;
		data -> fractal.re_factor = ((*data).fractal.max_re - (*data).fractal.min_re) / (width - 1);
		data -> fractal.im_factor = ((*data).fractal.max_im - (*data).fractal.min_im) / (height - 1);
	}

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

void	draw_mandelbrot(t_data	*data, int width, int height)
{
	t_complex c;
	t_complex z;
	int	x;
	int	y;

	data -> fractal.re_factor = (data -> fractal.max_re - data -> fractal.min_re) / (width - 1);
    data -> fractal.im_factor = (data -> fractal.max_im - data -> fractal.min_im) / (height - 1);
	y = 0;
	while (height > y)
	{
		x = 0;
		while (width > x)
		{
			c.re = data -> fractal.min_re + x * data -> fractal.re_factor/* * data -> ratio*/;
			c.im = data -> fractal.max_im - y * data -> fractal.im_factor/* * data -> ratio*/;
			z.re = 0;
			z.im = 0;
			my_mlx_pixel_put(data, x, y, compute_fractal(z,c));
			x++;
		}
		y++;
	}
}

void do_fractal(t_data	*data, int argc, char **argv)
{	
	init_fractal(data, 1000, 1000);
	if (data -> sign == 0)
		draw_mandelbrot(data, 1000, 1000);
	else if (data -> sign == 1)
	{
		data -> fractal.c.re = ft_atof(argv[2]);
		data -> fractal.c.im = ft_atof(argv[3]);
		draw_julia(data, 1000, 1000);
	}
	else if (data -> sign == 2)
		draw_sierpinski(data, 1000, 1000);
}
