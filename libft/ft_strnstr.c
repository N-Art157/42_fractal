/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:45:19 by nakagawashi       #+#    #+#             */
/*   Updated: 2023/08/01 21:25:37 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t len)
{
	int			i;
	size_t		h_len;

	if (*needle == 0)
		return ((char *)haystack);
	if (!haystack && !len)
		return (0);
	h_len = ft_strlen(haystack);
	while (len)
	{
		i = 0;
		while (*haystack == *(needle + i) && len && h_len--)
		{
			i++;
			if (*(needle + i) == '\0')
				return ((char *)haystack - i + 1);
			haystack++;
			len--;
		}
		if (len != 0)
			len--;
		h_len--;
		haystack++;
	}
	return (0);
}
