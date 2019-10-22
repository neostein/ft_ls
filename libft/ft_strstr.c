/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 22:47:20 by anabaoui          #+#    #+#             */
/*   Updated: 2018/10/12 17:14:22 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		if (ft_strchr(haystack, needle[i]))
		{
			while ((needle[i] == *haystack) && needle[i])
			{
				i++;
				haystack++;
			}
			if (needle[i] == '\0')
				return ((char *)(haystack - ft_strlen(needle)));
			haystack -= i;
		}
		haystack++;
	}
	return (0);
}
