/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_only.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:21:36 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/03 19:30:35 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flags_only(char *flags, t_info *files)
{
	if (ft_strchr(flags, 'o'))
		files->isflago = 1;
	if (ft_strchr(flags, 'g'))
		files->isflagg = 1;
	if (ft_strchr(flags, 'R'))
		with_flags_capr(files, flags);
	else
	{
		if (ft_strchr(flags, 'a'))
			flag_a(files, flags, ".");
		else
			flag_wa(files, flags, ".");
		if (ft_strchr(flags, 'l') || files->isflagg || files->isflago)
			prep_l(files, ".", flags, 2);
		else
			std_print(files->file);
		listfree(files->file);
	}
}

char	*print_capr_dir(t_itmp dk, char *path, char *dir)
{
	if (dk.i == 1)
		ft_putchar('\n');
	if (dir[0] != '/')
		dir = ft_strjoin(path, dir);
	if (dk.j == 2 || dk.i == 1)
	{
		ft_putstr((dir[0] == '.' && dk.j != 0) ? dir + 2 : dir);
		ft_putstr(":\n");
	}
	if (dk.j == 0 && !(dk.i))
	{
		ft_putstr(dir);
		ft_putstr(":\n");
	}
	return (dir);
}

char	*joindir(char *dir, char *file)
{
	char	*tmp;

	dir = ft_strjoin(dir, "/");
	tmp = ft_strjoin(dir, file);
	free(dir);
	return (tmp);
}

int		ft_intlen(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	sorting(t_info *new_files, char *flags)
{
	if (flags != NULL && ft_strchr(flags, 'r'))
	{
		if (flags != NULL && ft_strchr(flags, 't'))
		{
			bubble_sort_time_rev(&(new_files->file));
			bubble_sort_time_rev(&(new_files->dir));
		}
		else
		{
			bubble_sort_rev(&(new_files->file));
			bubble_sort_rev(&(new_files->dir));
		}
	}
	else if (flags != NULL && ft_strchr(flags, 't'))
	{
		bubble_sort_time(&(new_files->file));
		bubble_sort_time(&(new_files->dir));
	}
	else
	{
		bubble_sort(&(new_files->file));
		bubble_sort(&(new_files->dir));
	}
}
