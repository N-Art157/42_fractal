/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:58:00 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/02 04:46:23 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx_opengl_20191021/mlx.h"
#include "libft/libft.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	printf("%d\n",button);
	if (button == 1)
	{
		data -> ratio *= 0.9;
		printf("left\n");
	}
	else if (button == 2)
	{	
		data -> ratio *= 1.1;
		printf("right\n");
	}
	draw_mandelbrot(data, 1000, 1000);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 && argc != 4)
		ft_error();
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,1000, 1000, "fractol"); 
	data.img = mlx_new_image(data.mlx, 1000, 1000);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.ratio = 1.0;
	if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
		draw_mandelbrot(&data, 1000, 1000);
	else if (ft_strncmp(argv[1], "Julia", ft_strlen("Julia")) == 0 )
	{
		if (argc == 4)
		{
			draw_julia(&data, 1000, 1000, argv);
		}
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0,0);
	// mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 4, 0, mouse_hook, &data);
	mlx_loop(data.mlx);
}
