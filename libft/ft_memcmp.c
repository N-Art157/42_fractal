/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:13:10 by nakagawashi       #+#    #+#             */
/*   Updated: 2023/06/11 23:14:39 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void	*s1, const void	*s2, size_t n)
{
	unsigned char	*tos1;
	unsigned char	*tos2;

	tos1 = (unsigned char *)s1;
	tos2 = (unsigned char *)s2;
	while (n--)
	{
		if (*tos1 - *tos2 != 0)
			return (*tos1 - *tos2);
		tos1++;
		tos2++;
	}
	return (0);
}

