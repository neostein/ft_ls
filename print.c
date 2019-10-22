/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:34:30 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/03 20:12:03 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		std_print(t_nmfile *files)
{
	int i;

	i = 0;
	while (files)
	{
		ft_putstr(files->name);
		ft_putstr("\n");
		files = files->next;
	}
	return (1);
}

void	print_foldername(char *name)
{
	ft_putstr(name);
	ft_putendl(":");
}

void	flg_files_nocapr_print(t_itmp *dk, char *flags,
		t_info *argfiles, t_info *files)
{
	if (dk->i == 1)
		ft_putchar('\n');
	if (ft_strchr(flags, 'l') || files->isflagg || files->isflago)
	{
		if (dk->i == 1 || dk->j == 2)
			print_foldername(argfiles->dir->name);
		prep_l(files, argfiles->dir->name, flags, 1);
	}
	else
	{
		if (dk->i == 1 || dk->j == 2 || argfiles->unkn)
			print_foldername(argfiles->dir->name);
		dk->i = std_print(files->file);
		listfree(files->file);
		files->file = NULL;
	}
}

int		first_print(t_info *argfiles, char *flags)
{
	if (ft_strchr(flags, 'o'))
		argfiles->isflago = 1;
	if (ft_strchr(flags, 'g'))
		argfiles->isflagg = 1;
	if (argfiles->file->next)
		sorting(argfiles, flags);
	if (ft_strchr(flags, 'l') || argfiles->isflagg || argfiles->isflago)
		prep_l(argfiles, argfiles->file->name[0] == '/' ? "" : ".", flags, 0);
	else
		std_print(argfiles->file);
	return (1);
}

void	no_flags_dir_print(int dir_count,
		t_nmfile *dir, t_nmfile *file, t_lsread ls)
{
	t_nmfile *tmp;

	if (dir_count > 1 || file)
	{
		ft_putstr(dir->name);
		ft_putstr(":\n");
	}
	file = NULL;
	while ((ls.dp = readdir(ls.dirp)) != NULL)
		if (ls.dp->d_name[0] != '.')
			listadd(&(file), listnew_noflags(ls.dp->d_name));
	bubble_sort(&file);
	tmp = file;
	while (file)
	{
		ft_putendl(file->name);
		file = file->next;
	}
	listfree(tmp);
}
