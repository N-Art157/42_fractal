/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakagaw <anakagaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:46:40 by nakagawashi       #+#    #+#             */
/*   Updated: 2023/07/28 15:40:25 by anakagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	uc;
	unsigned char	*p;

	uc = c;
	p = (unsigned char *)b;
	while (len-- > 0)
	{
		*p++ = uc;
	}
	return (b);
}
