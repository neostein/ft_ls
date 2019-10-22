/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 22:20:42 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/03 16:44:49 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			listcount(t_nmfile *file)
{
	int i;

	i = 0;
	while (file)
	{
		file = file->next;
		i++;
	}
	return (i);
}

t_nmfile	*listnew_noflags(char *name)
{
	t_nmfile *new;

	if (!(new = malloc(sizeof(t_nmfile))))
		exit(1);
	new->name = ft_strdup(name);
	return (new);
}

void		no_args(t_info *files)
{
	struct stat	info;
	t_lsread	ls;
	t_nmfile	*tmp;

	if ((ls.dirp = opendir(".")) == NULL)
		perror("opendir() error");
	while ((ls.dp = readdir(ls.dirp)) != NULL)
	{
		if (ls.dp->d_name[0] != '.')
			listadd(&(files->file), listnew(ls.dp->d_name, &info));
	}
	closedir(ls.dirp);
	bubble_sort(&(files->file));
	tmp = files->file;
	while (files->file)
	{
		ft_putstr(files->file->name);
		ft_putchar('\n');
		files->file = files->file->next;
	}
	listfree(tmp);
}

void		no_flags_dir(t_nmfile *file, t_nmfile *dir)
{
	t_lsread	ls;
	int			dir_count;

	bubble_sort(&(dir));
	dir_count = listcount(dir);
	while (dir)
	{
		if (file)
			ft_putchar('\n');
		if ((ls.dirp = opendir(dir->name)) == NULL)
			no_permission(dir->name);
		if (permcheck(dir->name) == 'r')
		{
			no_flags_dir_print(dir_count, dir, file, ls);
			closedir(ls.dirp);
		}
		if ((dir = dir->next))
			ft_putchar('\n');
	}
}

void		no_flags(t_info *files)
{
	t_nmfile *head;

	head = files->file;
	if (head)
	{
		bubble_sort(&(head));
		while (head)
		{
			ft_putendl(head->name);
			head = head->next;
		}
		listfree(files->file);
	}
	if (files->dir)
	{
		no_flags_dir(files->file, files->dir);
		listfree(files->dir);
	}
}
