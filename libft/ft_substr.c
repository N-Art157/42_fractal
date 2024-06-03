/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:00:01 by anakagaw          #+#    #+#             */
/*   Updated: 2023/08/01 21:50:34 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_substr(char const	*s, unsigned int start, size_t	len)
{
	char	*substring;
	int		n;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) <= start || len == 0)
	{
		substring = malloc(sizeof(char));
		*substring = '\0';
		return (substring);
	}
	substring = malloc(sizeof(char) * (len + 1));
	if (substring == NULL)
		return (NULL);
	while (start--)
		s++;
	n = 0;
	while ((size_t)n < len && s[n])
	{
		substring[n] = s[n];
		n++;
	}
	substring[n] = '\0';
	return (substring);
}
