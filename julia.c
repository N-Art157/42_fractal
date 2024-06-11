/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:31:47 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/10 13:54:47 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_data *data, int width, int height)
{
	t_complex c;
	t_complex z;
	int	x;
	int	y;

	data -> fractal.re_factor = (data -> fractal.max_re - data -> fractal.min_re) / (width - 1);
    data -> fractal.im_factor = (data -> fractal.max_im - data -> fractal.min_im) / (height - 1);
	z.re = 0;
	z.im = 0;
	c.re = data -> fractal.c.re;
	c.im = data -> fractal.c.im;
	y = 0;
	while (height > y)
	{
		x = 0;
		while (width > x)
		{
			z.re = data -> fractal.min_re + x * data -> fractal.re_factor;
			z.im = data -> fractal.max_im - y * data -> fractal.im_factor;
			my_mlx_pixel_put(data, x, y, compute_fractal(z,c));
			x++;
		}
		y++;
	}
}

void	draw_sierpinski(t_data *data, int width, int height)
{
	int	x;
	int	y;
	int color;
	int	tx;
	int	ty;

	y = 0;
	while (height > y)
	{
		ty = data->fractal.min_im + y * data -> fractal.im_factor;
		x = 0;
		while (width > x)
		{
			tx = data->fractal.min_re + x * data -> fractal.re_factor;
			if ((tx & ty) == 0)
			{
				color = 0xff0000/*((x * 255 / width) << 16 | (y * 255 / height) << 8)*/;
				my_mlx_pixel_put(data, x, y, color);
			}
			else
				my_mlx_pixel_put(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
