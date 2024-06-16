/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:27:39 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/16 14:18:04 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putendl_fd("Please enter 'Julia' or 'Mandelbrot'.", 1);
	ft_putendl_fd("If you entered 'Julia',please enter c_re and c_im.", 1);
	ft_putendl_fd("Ensure that -2.0 < c_re,c_im < 2.0.", 1);
	exit(1);
}

void	error_check(int argc, char **argv, t_data *data)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
			data -> sign = 0;
		else if (ft_strncmp(argv[1], "ss", ft_strlen("ss")) == 0)
			data -> sign = 2;
		else
			ft_error();
	}
	else if (argc == 4)
	{
		if (ft_strncmp(argv[1], "Julia", ft_strlen("Julia")) == 0)
		{
			data -> sign = 1;
			if (!ft_isnum(argv[2]) || !ft_isnum(argv[3]))
				ft_error();
		}
		else
			ft_error();
	}
	else
		ft_error();
}
