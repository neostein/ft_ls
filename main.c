/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:45:53 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/03 20:11:16 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_ldata(t_info *files, char *dir)
{
	files->maxxpw_name = maxxstr("pw_name", files->file, dir);
	files->maxxgr_name = maxxstr("gr_name", files->file, dir);
	files->maxxnlink = maxxint("nlink", files->file, dir);
	files->maxxsize = maxxint("size", files->file, dir);
}

void	flags_files_nocapr(t_info *argfiles, t_info *files,
						char *flags, t_itmp dk)
{
	t_nmfile	*tmp;

	tmp = argfiles->dir;
	while (argfiles->dir)
	{
		if (flags != NULL && ft_strchr(flags, 'a'))
			flag_a(files, flags, argfiles->dir->name);
		else
		{
			listfree(files->file);
			flag_wa(files, flags, argfiles->dir->name);
		}
		flg_files_nocapr_print(&dk, flags, argfiles, files);
		argfiles->dir = argfiles->dir->next;
	}
	listfree(tmp);
}

void	flags_files(t_info *argfiles, t_info *files, char *flags)
{
	t_itmp	dk;

	dk.i = 0;
	dk.j = 0;
	if (ft_strchr(flags, 'o'))
		files->isflago = 1;
	if (ft_strchr(flags, 'g'))
		files->isflagg = 1;
	if (argfiles->file)
		dk.i = first_print(argfiles, flags);
	if (argfiles->dir)
	{
		if (argfiles->dir->next)
			dk.j = 2;
		else
			dk.j = 1;
		if (argfiles->dir->next)
			sorting(argfiles, flags);
		if (flags != NULL && ft_strchr(flags, 'R'))
			flag_capr2(argfiles, argfiles->dir->name[0] == '/' ? "" : ".",
					flags, dk);
		else
			flags_files_nocapr(argfiles, files, flags, dk);
	}
	listfree(argfiles->file);
}

void	listalloc(t_info **new_files)
{
	if (!(*new_files = (t_info *)malloc(sizeof(t_info))))
		exit(1);
	(*new_files)->file = NULL;
	(*new_files)->dir = NULL;
	(*new_files)->unkn = NULL;
	(*new_files)->maxxsize = 7;
	(*new_files)->isdevicefile = 7;
	(*new_files)->isflago = 0;
	(*new_files)->isflagg = 0;
}

int		main(int ac, char **av)
{
	int			i;
	t_info		*files;
	t_info		*argfiles;
	char		*flags;

	listalloc(&files);
	listalloc(&argfiles);
	if (ac == 1 || (ac == 2 && !ft_strcmp(av[1], "--")))
		no_args(files);
	else if (ac != 1)
	{
		i = 1;
		while (i < ac)
			parsing(av[i++], argfiles, &flags);
		unknown_files(argfiles->unkn);
		if (!flags)
			no_flags(argfiles);
		else if (flags && (argfiles->file || argfiles->dir))
			flags_files(argfiles, files, flags);
		else if (flags && !(argfiles->file || argfiles->dir) && !argfiles->unkn)
			flags_only(flags, files);
	}
	free(files);
	free(argfiles);
}
