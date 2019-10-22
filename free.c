/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:21:44 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/09/28 18:22:20 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	listfree(t_nmfile *file)
{
	t_nmfile	*tmp;

	while (file)
	{
		free(file->name);
		tmp = file->next;
		free(file);
		file = tmp;
	}
	free(file);
}
