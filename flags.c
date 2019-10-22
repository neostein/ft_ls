/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:09:08 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/22 21:31:44 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		flag_a(t_info *files, char *flags, char *dir)
{
	struct stat	info;
	t_lsread	ls;
	char		*tmp;

	ls.dirp = opendir(dir);
	while ((ls.dp = readdir(ls.dirp)) != NULL)
	{
		tmp = joindir(dir, ls.dp->d_name);
		lstat(tmp, &info);
		free(tmp);
		listadd(&(files->file), listnew(ls.dp->d_name, &info));
		if (strchr(flags, 'R'))
			if (file_type(info.st_mode) == 'd' &&
					ft_strcmp(ls.dp->d_name, "..")
					&& ft_strcmp(ls.dp->d_name, "."))
				listadd(&(files->dir), listnew(ls.dp->d_name, &info));
		if (file_type(info.st_mode) == 'c' || file_type(info.st_mode) == 'b')
			files->isdevicefile = 1;
	}
	closedir(ls.dirp);
	sorting(files, flags);
}

void		flag_wa(t_info *files, char *flags, char *dir)
{
	struct stat	inf;
	t_lsread	ls;
	char		*tmp;

	if(!(ls.dirp = opendir(dir)))
	{
			no_permission(dir);
			return ;
	}
	while ((ls.dp = readdir(ls.dirp)) != NULL)
	{
		if (ls.dp->d_name[0] != '.')
		{
			tmp = joindir(dir, ls.dp->d_name);
			lstat(tmp, &inf);
			free(tmp);
			listadd(&(files->file), listnew(ls.dp->d_name, &inf));
			if (strchr(flags, 'R'))
				if (file_type(inf.st_mode) == 'd')
					listadd(&(files->dir), listnew(ls.dp->d_name, &inf));
			if (file_type(inf.st_mode) == 'c' || file_type(inf.st_mode) == 'b')
				files->isdevicefile = 1;
		}
	}
	closedir(ls.dirp);
	sorting(files, flags);
}

int			devicefile_maj(dev_t bufst_dev)
{
	int major;

	major = bufst_dev;
	while ((major / 256) > 0)
		major = major / 256;
	return (major);
}

int			flag_l(t_info *files, char *tmp, struct stat buf, char *dir)
{
	struct passwd	*passwd;
	struct group	*group;

	passwd = getpwuid(buf.st_uid);
	group = getgrgid(buf.st_gid);
	ft_putchar(file_type(buf.st_mode));
	tmp = joindir(dir, files->file->name);
	permissions(buf.st_mode, tmp);
	free(tmp);
	add_spaces(buf.st_nlink, files->maxxnlink - 1);
	ft_putnbr(buf.st_nlink);
	print_o_g(files, passwd, group);
	if (files->isflagg && files->isflago)
		ft_putchar(' ');
	add_spaces(0, files->maxxgr_name - ft_strlen(group->gr_name) - 1);
	print_size_device(buf, files);
	ft_putstr(" ");
	mtimenewline(buf.st_mtimespec.tv_sec);
	ft_putstr(" ");
	ft_putstr(files->file->name);
	if (file_type(buf.st_mode) == 'l')
		links_l(files, dir);
	return (1);
}
