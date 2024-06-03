/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:04:31 by nakagawashi       #+#    #+#             */
/*   Updated: 2023/06/10 17:14:37 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*c;
	const char	*d;

	c = (char *)dst;
	d = src;
	if (!dst && !src)
		return (NULL);
	if (dst <= src)
	{
		while (n--)
		{
			*c++ = *d++;
		}
	}
	else
	{
		c += (n - 1);
		d += (n - 1);
		while (n--)
		{
			*c-- = *d--;
		}
	}
	return (dst);
}
