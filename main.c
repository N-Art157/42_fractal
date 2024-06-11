/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:58:00 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/10 14:28:22 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	main(int argc, char **argv)
{
	t_data	data;

	error_check(argc, argv, &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,1000, 1000, "fractol"); 
	data.img = mlx_new_image(data.mlx, 1000, 1000);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.ratio = 1.0;
	do_fractal(&data, argc, argv);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0,0);
	mlx_hook(data.win, 4, 0, mouse_hook, &data);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, finish, &data);;
	mlx_loop(data.mlx);
}
