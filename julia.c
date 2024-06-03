/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:31:47 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/02 03:26:12 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include "fractol.h"
#include <stdio.h>

void	draw_julia(t_data *img, int width, int height, char **argv)
{
	t_fractal fractal;
	t_complex c;
	t_complex z;
	int	x;
	int	y;

	init_fractal(&fractal, width, height);
	c.re = ft_atof(argv[2]);
	c.im = ft_atof(argv[3]);
	z.re = 0;
	z.im = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			z.re = fractal.min_re + x * fractal.re_factor;
			z.im = fractal.max_im - y * fractal.im_factor;
			my_mlx_pixel_put(img, x, y, compute_fractal(z,c));
			x++;
		}
		y++;
	}
}
