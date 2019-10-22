/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:27:07 by anabaoui          #+#    #+#             */
/*   Updated: 2018/10/20 16:12:20 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	int		first;
	int		last;
	int		length;

	if (!s)
		return (0);
	first = first_spaces(s);
	last = last_spaces(s);
	if (ft_strlen(s) == 0)
		length = 0;
	else
		length = ft_strlen(s) - (first + last);
	if (length < 0)
		length = 0;
	ptr = (char *)malloc(length + 1);
	if (!ptr)
		return (0);
	ft_strncpy(ptr, (s + first), length);
	ptr[length] = '\0';
	return (ptr);
}
