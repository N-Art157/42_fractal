/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:06:42 by anakagaw          #+#    #+#             */
/*   Updated: 2023/07/16 17:01:59 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	char		*dest;
	char		*dest2;
	size_t		i;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	dest = malloc(sizeof(char) * (len + 1));
	dest2 = dest;
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*dest = f(i, s[i]);
		dest++;
		i++;
	}
	*dest = '\0';
	return (dest2);
}
