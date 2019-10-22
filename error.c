/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:03:09 by nsaber            #+#    #+#             */
/*   Updated: 2019/10/03 15:26:10 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		unknown_files(t_nmfile *files)
{
	int			len;
	t_nmfile	*tmp;

	if (files)
	{
		bubble_sort(&(files));
		tmp = files;
		while (files)
		{
			len = ft_strlen(files->name);
			write(2, "ft_ls: ", 7);
			if (len == 0)
				write(2, "fts_open", 8);
			else
				ft_putstr(files->name);
			write(2, ": No such file or directory\n", 28);
			if (len == 0)
				exit(1);
			files = files->next;
		}
		listfree(tmp);
	}
	return (0);
}

void	no_permission(char *dir)
{
	write(2, "ft_ls: ", 7);
	if (dir[0] == '.')
		dir = dir + 2;
	write(2, dir, ft_strlen(dir));
	write(2, ": ", 2);
	perror("");
}

void	illegal_option(char flag)
{
	write(2, "ft_ls: illegal option -- ", 25);
	ft_putchar(flag);
	write(2, "\nusage: ft_ls [-larR1tog] ", 26);
	write(2, "[file ...]\n", 11);
	exit(1);
}

void	error_perm(char *dir)
{
	char *tmp;

	while (*dir)
		dir++;
	while (*dir != '/')
		dir--;
	tmp = dir + 1;
	write(2, "ft_ls: ", 7);
	write(2, dir + 1, ft_strlen(dir) - 1);
	write(2, ": ", 2);
	perror("");
}
