/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:35:17 by nakagawashi       #+#    #+#             */
/*   Updated: 2023/06/10 15:55:44 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*c;
	const char	*d;

	c = dst;
	d = src;
	if (!c && !d)
		return (dst);
	while (n-- > 0)
	{
		*c++ = *d++;
	}
	return (dst);
}
