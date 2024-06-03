/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:52:49 by anakagaw          #+#    #+#             */
/*   Updated: 2023/07/09 22:30:18 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	writer(int nb, int fd)
{
	char	str[13];
	int		count;

	count = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		str[count] = nb % 10 + '0';
		count++;
		nb /= 10;
	}
	count--;
	while (count >= 0)
	{
		write(fd, &str[count], 1);
		count--;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write (fd, "-2147483648", 11);
	}
	else if (nb == 0)
	{
		write (fd, "0", 1);
	}
	else
	{
		writer (nb, fd);
	}
}

