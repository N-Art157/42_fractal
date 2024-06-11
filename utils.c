/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:03:57 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/06/10 13:22:45 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool ft_isnum(char *str)
{
	bool 	has_digit;
	bool	has_dot;

	has_digit = false;
	has_dot = false;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			has_digit = true;
		else if (*str == '.')
		{
			if (has_dot == true)
				return false;
			has_dot = true;
		}
		else
			return false;
		str++;
	}
	return has_digit;
}
