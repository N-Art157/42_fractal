/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:27:39 by nakagawashi       #+#    #+#             */
/*   Updated: 2024/05/29 17:33:03 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void	ft_error(void)
{
	ft_putstr_fd("Please Enter Julia or Mandelbrot", 1);
	exit(0);
}