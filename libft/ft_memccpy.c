/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:04:17 by anabaoui          #+#    #+#             */
/*   Updated: 2018/10/20 17:35:23 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptrdst;
	char	*ptrsrc;
	char	uc;

	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	uc = c;
	while (n--)
	{
		*ptrdst = *ptrsrc;
		ptrdst++;
		if (*ptrsrc == uc)
			return ((void *)ptrdst);
		ptrsrc++;
	}
	return (NULL);
}
