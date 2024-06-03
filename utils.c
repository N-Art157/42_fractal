/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:03:57 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/01 23:43:32 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include "fractol.h"

double atof_decimal(char *str, double n)
{
	double d;

	d  = 0.1;
	while (*str && ft_isdigit(*str))
	{
		n += d * (*str++ - '0');
		d *= 0.1;
	}
	return (n);
}

double	ft_atof(char *str)
{
	double n;
	int sign;

	sign = 1;
	n = 0.0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str))
			n = n * 10.0 + (*str++ - '0');
		if (*str == '.')
		{
			str++;
			n = atof_decimal(str, n);
			break;
		}
		else if (!ft_isdigit(*str))
			break;
	}
	return (sign * n);
}
