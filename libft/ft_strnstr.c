/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:49:27 by anabaoui          #+#    #+#             */
/*   Updated: 2018/10/12 20:13:27 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int len1;

	len1 = len;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len1--)
	{
		i = 0;
		if (ft_strchr(haystack, needle[i]))
		{
			len = len1 + 1;
			while ((needle[i] == *haystack) && needle[i] && len--)
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
