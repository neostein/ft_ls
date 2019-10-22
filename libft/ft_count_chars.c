/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:58:21 by anabaoui          #+#    #+#             */
/*   Updated: 2018/10/20 16:01:28 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_count_chars(char const *str, int *ptr, char c)
{
	int		i;
	int		start;
	int		end;
	char	*word;
	int		j;

	i = *ptr;
	j = -1;
	while (str[i] == c && str[i])
		i++;
	start = i;
	while (str[i] != c && str[i])
		i++;
	end = i;
	word = malloc(sizeof(*str) * ((end - start) + 1));
	if (!word)
		return (0);
	*ptr = i;
	while (++j < (end - start))
		word[j] = str[start + j];
	word[j] = '\0';
	return (word);
}
