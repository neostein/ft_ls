/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 09:45:02 by anabaoui          #+#    #+#             */
/*   Updated: 2018/10/20 16:22:42 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*ptr;
	int				length;
	unsigned int	nbr;

	length = nbr_len(n);
	ptr = (char *)malloc(length + 1);
	if (!ptr)
		return (0);
	ptr[length--] = '\0';
	if (n == 0)
		ptr[length] = 0 + '0';
	if (n < 0)
	{
		ptr[0] = '-';
		nbr = n * -1;
	}
	else
		nbr = n;
	while (nbr != 0)
	{
		ptr[length--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ptr);
}
