/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:40:16 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/02 22:52:27 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_nmfile	*listnew(char *name, struct stat *info)
{
	t_nmfile *new;

	if (!(new = malloc(sizeof(t_nmfile))))
		exit(1);
	new->name = ft_strdup(name);
	new->mtime = (*info).st_mtimespec.tv_sec;
	new->mtimenano = (*info).st_mtimespec.tv_nsec;
	return (new);
}

void		listadd(t_nmfile **head, t_nmfile *new)
{
	new->next = *head;
	*head = new;
}

void		store_files(char *av, t_info *files, char *flags)
{
	DIR			*dirp;
	struct stat info;

	if (lstat(av, &info) < 0)
		listadd(&(files->unkn), listnew(av, &info));
	else if (file_type(info.st_mode) == 'd')
		listadd(&(files->dir), listnew(av, &info));
	else if (file_type(info.st_mode) == 'l')
	{
		if ((dirp = opendir(av)) != NULL)
		{
			if (!flags || (flags && ft_strchr(flags, '1')))
				listadd(&(files->dir), listnew(av, &info));
			else
				listadd(&(files->file), listnew(av, &info));
			closedir(dirp);
		}
		else
			listadd(&(files->file), listnew(av, &info));
	}
	else
		listadd(&(files->file), listnew(av, &info));
}

char		*store_flags(char *arg)
{
	char		*flags;
	static char tr_flag[10];
	int			i;
	static int	j = 0;

	i = 1;
	flags = ft_strdup("alrRt1go");
	while (arg[i] != '\0')
	{
		if (ft_strchr(flags, arg[i]))
		{
			if (!ft_strchr(tr_flag, arg[i]))
				store_flag_og(arg[i], tr_flag, &j);
		}
		else
			illegal_option(arg[i]);
		i++;
	}
	free(flags);
	return (tr_flag);
}

int			parsing(char *av, t_info *files, char **flags)
{
	static int stop = 0;

	if (ft_strequ(av, "--") && stop)
		store_files(av, files, *flags);
	if ((av[0] != '-' || ft_strequ(av, "-") || ft_strequ(av, "--")))
	{
		if (!ft_strequ(av, "--"))
			store_files(av, files, *flags);
		stop = 1;
	}
	if ((av[0] == '-' && stop))
		if (!ft_strequ(av, "-") && !ft_strequ(av, "--"))
			store_files(av, files, *flags);
	if (!stop)
		*flags = store_flags(av);
	return (1);
}
