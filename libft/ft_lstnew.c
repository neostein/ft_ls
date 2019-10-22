/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:14:12 by anabaoui          #+#    #+#             */
/*   Updated: 2018/10/20 12:42:17 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;
	char	*str;

	if (!(ptr = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (!(str = (char *)malloc(sizeof(content) * content_size)))
		return (0);
	if (!content)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	else
	{
		ft_memcpy(str, (char *)content, content_size);
		ptr->content = (void *)str;
		ptr->content_size = content_size;
	}
	ptr->next = NULL;
	return (ptr);
}
