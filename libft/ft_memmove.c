/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:56:17 by anabaoui          #+#    #+#             */
/*   Updated: 2018/10/10 12:24:29 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *ptrdst;

	ptrdst = (char *)malloc(len * sizeof(char));
	ft_memcpy(ptrdst, src, len);
	ft_memcpy(dst, ptrdst, len);
	return (dst);
}
