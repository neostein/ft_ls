/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:35:06 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/03 19:19:14 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	bubble_sort(t_nmfile **files)
{
	char		*temp;
	time_t		tmp;
	t_nmfile	*i;
	t_nmfile	*j;

	i = *files;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (ft_strcmp(i->name, j->name) > 0)
			{
				temp = (*j).name;
				tmp = j->mtime;
				j->name = (*i).name;
				j->mtime = i->mtime;
				i->name = temp;
				i->mtime = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	swap_sort(t_nmfile *i, t_nmfile *j, char c)
{
	time_t		tmp;
	long		tmp2;
	char		*temp;

	temp = (*j).name;
	tmp = j->mtime;
	j->name = (*i).name;
	j->mtime = i->mtime;
	i->name = temp;
	i->mtime = tmp;
	if (c == 't')
	{
		tmp2 = j->mtimenano;
		j->mtimenano = i->mtimenano;
		i->mtimenano = tmp2;
	}
}

void	bubble_sort_time(t_nmfile **files)
{
	t_nmfile	*i;
	t_nmfile	*j;

	i = *files;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->mtime < j->mtime)
				swap_sort(i, j, 't');
			if (i->mtime == j->mtime)
			{
				if (ft_strcmp(i->name, j->name) > 0)
					swap_sort(i, j, 't');
				if (i->mtimenano < j->mtimenano)
					swap_sort(i, j, 't');
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	bubble_sort_time_rev(t_nmfile **files)
{
	t_nmfile	*i;
	t_nmfile	*j;

	i = *files;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->mtime > j->mtime)
				swap_sort(i, j, 'N');
			if (i->mtime == j->mtime)
			{
				if (ft_strcmp(i->name, j->name) < 0)
					swap_sort(i, j, 'N');
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	bubble_sort_rev(t_nmfile **files)
{
	char		*temp;
	time_t		tmp;
	t_nmfile	*i;
	t_nmfile	*j;

	i = *files;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (ft_strcmp(i->name, j->name) < 0)
			{
				temp = (*j).name;
				tmp = j->mtime;
				j->name = (*i).name;
				j->mtime = i->mtime;
				i->name = temp;
				i->mtime = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}
