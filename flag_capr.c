/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_capr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 22:19:04 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/22 21:30:42 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	afterprep_capr(t_info *new_files, char *flags, char *dir, t_itmp dk)
{
	sorting(new_files, flags);
	if (ft_strchr(flags, 'l') || new_files->isflagg || new_files->isflago)
		prep_l(new_files, dir, flags, 1);
	else
		std_print(new_files->file);
	listfree(new_files->file);
	new_files->file = NULL;
	dk.i = 1;
	flag_capr2(new_files, dir, flags, dk);
}

int		prep_capr(char *dir, char *flags, t_info *new_files, t_itmp dk)
{
	struct stat info;
	char		*tmp;
	t_lsread	ls;

	if ((ls.dirp = opendir(dir)) == NULL)
	{
		error_perm(dir);
		return (1);
	}
	while ((ls.dp = readdir(ls.dirp)) != NULL)
		if (ls.dp->d_name[0] != '.' || ft_strchr(flags, 'a'))
		{
			tmp = joindir(dir, ls.dp->d_name);
			lstat(tmp, &info);
			if (((info.st_mode & S_IRUSR) ||
						(info.st_mode & S_IRGRP) || (info.st_mode & S_IROTH)))
				listadd(&(new_files->file), listnew(ls.dp->d_name, &info));
			if (file_type(info.st_mode) == 'd' && ft_strcmp(ls.dp->d_name,
						"..") && ft_strcmp(ls.dp->d_name, "."))
				listadd(&(new_files->dir), listnew(ls.dp->d_name, &info));
			free(tmp);
		}
	closedir(ls.dirp);
	afterprep_capr(new_files, flags, dir, dk);
	return (1);
}

void	with_flags_capr(t_info *files,
		char *flags)
{
	t_itmp dk;

	dk.i = 1;
	dk.j = 0;
	if (ft_strchr(flags, 'a'))
		flag_a(files, flags, ".");
	else
		flag_wa(files, flags, ".");
	if (ft_strchr(flags, 'l') || files->isflagg || files->isflago)
		prep_l(files, ".", flags, 1);
	else
		std_print(files->file);
	listfree(files->file);
	files->file = NULL;
	flag_capr2(files, ".", flags, dk);
}

void	beforeprep_capr(t_info *files, char *path, char *flags, t_itmp dk)
{
	t_info		*new_files;
	t_lsread	ls;
	char		*kk;

	listalloc(&new_files);
	if (ft_strchr(flags, 'o'))
		new_files->isflago = 1;
	if (ft_strchr(flags, 'g'))
		new_files->isflagg = 1;
	while (files->dir)
	{
		kk = print_capr_dir(dk, path, files->dir->name);
		if (permcheck(kk) == 'r')
			dk.i = prep_capr(kk, flags, new_files, dk);
		else if (!(ls.dirp = opendir(kk)))
			no_permission(kk);
		else
			closedir(ls.dirp);
		if (files->dir->name[0] != '/')
			free(kk);
		files->dir = files->dir->next;
	}
	free(new_files);
}

void	flag_capr2(t_info *files, char *path, char *flags, t_itmp dk)
{
	t_nmfile	*tmp;

	if (files->dir)
	{
		if (files->dir->name[0] != '/' && !ft_strequ(path, "/"))
			if ((files->maxxsize = 1))
				path = ft_strjoin(path, "/");
		tmp = files->dir;
		beforeprep_capr(files, path, flags, dk);
		listfree(tmp);
		if (files->maxxsize == 1)
			free(path);
	}
}
