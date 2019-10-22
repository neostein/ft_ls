/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:54:03 by anabaoui          #+#    #+#             */
/*   Updated: 2018/10/20 14:49:57 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	int		r;

	dlen = ft_strlen(dst);
	if (dlen < size)
	{
		r = dlen + ft_strlen(src);
		size -= dlen;
	}
	else
	{
		r = size + ft_strlen(src);
		size = 0;
	}
	while (*src != '\0' && size > 1)
	{
		dst[dlen] = *src;
		src++;
		size--;
		dlen++;
	}
	dst[dlen] = '\0';
	return (r);
}
