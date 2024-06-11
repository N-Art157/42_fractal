/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:18:36 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/10 14:13:40 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	compute_c(t_data *data, t_complex clicked, double new_w, double new_h)
{
	if (data -> sign == 2)
	{
		new_w = (data->fractal.max_re - data->fractal.min_re) * data->ratio;
		new_h = (data->fractal.max_im - data->fractal.min_im) * data->ratio;
		data->fractal.min_re = clicked.re - (new_w / 2);
		data->fractal.max_re = clicked.re + (new_w / 2);
		data->fractal.min_im = clicked.im - (new_h / 2);
		data->fractal.max_im = clicked.im + (new_h / 2);
		data->fractal.re_factor *= data->ratio;
		data->fractal.im_factor *= data->ratio;
	}
	else
	{
		new_w = (data->fractal.max_re - data->fractal.min_re) * data->ratio;
		new_h = (data->fractal.max_im - data->fractal.min_im) * data->ratio;
		data->fractal.min_re = clicked.re - (new_w / 2);
		data->fractal.max_re = clicked.re + (new_w / 2);
		data->fractal.min_im = clicked.im - (new_h / 2);
		data->fractal.max_im = clicked.im + (new_h / 2);
	}
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	t_complex	clicked;
	double	new_width;
	double	new_height;

	if (data -> sign == 2)
	{
		clicked.re = (double)x;
		clicked.im = (double)y;
	}
	else
	{
		clicked.re = data->fractal.min_re + x * data->fractal.re_factor;
		clicked.im = data->fractal.max_im - y * data->fractal.im_factor;
	}
	if (button == 1)
		data -> ratio = 0.9;
	else if (button == 2)
		data -> ratio = 1.1;
	compute_c(data, clicked, new_width, new_height);
	if (data -> sign == 0)
		draw_mandelbrot(data, 1000, 1000);
	else if (data -> sign == 1)
		draw_julia(data, 1000, 1000);
	else if (data -> sign == 2)
		draw_sierpinski(data, 1000, 1000);
	mlx_put_image_to_window(data -> mlx, data -> win, data -> img, 0, 0);
	return (0);
}
int	key_hook(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (key);
}

int	finish(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}