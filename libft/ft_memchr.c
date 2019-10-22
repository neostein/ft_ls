/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:40:32 by anabaoui          #+#    #+#             */
/*   Updated: 2018/10/20 17:36:02 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptrs;

	ptrs = (char *)s;
	while (n--)
	{
		if ((unsigned char)*ptrs == (unsigned char)c)
		{
			return (ptrs);
		}
		ptrs++;
	}
	return (NULL);
}
