/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:02:48 by anabaoui          #+#    #+#             */
/*   Updated: 2018/10/20 12:10:44 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlst;
	t_list *tlst;

	if (!lst)
		return (0);
	tlst = f(lst);
	nlst = tlst;
	while (lst->next)
	{
		lst = lst->next;
		tlst->next = f(lst);
		tlst = tlst->next;
	}
	return (nlst);
}
