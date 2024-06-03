/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakagawashinta <nakagawashinta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:36:30 by anakagaw          #+#    #+#             */
/*   Updated: 2023/08/01 20:15:19 by nakagawashi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_start(char	const *s1, char const *set)
{
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen (s1);
	i = 0;
	while ((unsigned int)i < len)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

int	ft_end(char	const *s1, char const *set)
{
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen (s1);
	j = len - 1;
	while (j >= 0)
	{
		i = 0;
		while (set[i])
		{
			if (s1[j] == set[i])
				break ;
			i++;
		}
		if (set[i] == '\0')
			break ;
		j--;
	}
	return (j);
}

char	*ft_strtrim(char	const *s1, char	const *set)
{
	int		start;
	int		end;
	char	*new;
	char	*new2;

	if (s1 == NULL || !*s1)
		return ("");
	if (set == NULL || !*set)
		return ((char *)s1);
	start = ft_start (s1, set);
	end = ft_end (s1, set);
	if (start > end)
		return ("");
	new = malloc (sizeof(char) * (end - start + 2));
	if (new == NULL)
		return (NULL);
	new2 = new;
	while (start <= end)
	{
		*new = s1[start];
		new++;
		start++;
	}
	*new = '\0';
	return (new2);
}
