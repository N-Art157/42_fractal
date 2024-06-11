/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:45:34 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/10 14:19:37 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "minilibx_opengl_20191021/mlx.h"
#include "libft/libft.h"

#include <stdio.h>
#include <stdbool.h>

typedef	struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef	struct s_fractal
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re_factor;
	double	im_factor;

	t_complex	c;
}				t_fractal;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx;
	void	*win;

	double	ratio;

	int sign;

	t_fractal fractal;
}				t_data;

void	init_fractal(t_data *data, int width, int height);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_error(void);
void	draw_mandelbrot(t_data	*data, int width, int height);
void	draw_julia(t_data *data, int width, int height);
void	draw_sierpinski(t_data *data, int width, int height);
int	compute_fractal(t_complex z, t_complex c);
void	set_args(double c_re, double c_im);
double	ft_atof(char *str);
int	mouse_hook(int button, int x, int y, t_data *data);
int	key_hook(int key, t_data *data);
int	finish(t_data *data);
void do_fractal(t_data	*data, int argc, char **argv);
bool ft_isnum(char *str);
void error_check(int argc, char **argv, t_data *data);
#endif