/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:45:34 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/02 03:56:32 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx;
	void	*win;

	double	ratio;
}				t_data;


typedef	struct s_fractal
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re_factor;
	double	im_factor;
}				t_fractal;

typedef	struct s_complex
{
	double	re;
	double	im;
}				t_complex;

void	init_fractal(t_fractal *fractal, int width, int height);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_error(void);
void	draw_mandelbrot(t_data	*img, int width, int height);
void	draw_julia(t_data *img, int width, int height, char **argv);
int	compute_fractal(t_complex z, t_complex c);
void	set_args(double c_re, double c_im);
double	ft_atof(char *str);

#endif