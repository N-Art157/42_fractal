/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:48:46 by nakagawashi       #+#    #+#             */
/*   Updated: 2023/08/01 20:23:27 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	char		c_cp;
	const char	*ss;
	int			n;

	if (*s == '\0')
		return (NULL);
	c_cp = (char)c;
	n = ft_strlen (s) + 1;
	ss = NULL;
	while (n--)
	{
		if (*s == c_cp)
		{
			ss = s;
		}
		s++;
	}
	if (ss != NULL)
		return ((char *)ss);
	return (0);
}
