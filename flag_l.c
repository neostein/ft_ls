/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:19:34 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/01 17:36:05 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		prep_l2(t_info *files, char *dir, char *flags, int k)
{
	struct stat	buf;
	char		*tmp1;

	while (files->file)
	{
		if (k == 1)
			tmp1 = joindir(dir, files->file->name);
		else
			tmp1 = files->file->name;
		lstat(tmp1, &buf);
		if (k == 1)
			free(tmp1);
		flag_l(files, flags, buf, dir);
		ft_putstr("\n");
		files->file = files->file->next;
	}
}

void		prep_l(t_info *files, char *dir, char *flags, int k)
{
	struct stat	buf;
	char		*tmp1;
	t_nmfile	*tmp;

	if (files->file)
	{
		tmp1 = joindir(dir, files->file->name);
		if (lstat(tmp1, &buf) == -1)
		{
			free(tmp1);
			return ;
		}
		free(tmp1);
		if (k != 0)
			totalsum(files->file, dir);
		init_ldata(files, dir);
	}
	tmp = files->file;
	prep_l2(files, dir, flags, k);
	listfree(tmp);
}

int			totalsum(t_nmfile *head, char *dir)
{
	int			i;
	struct stat	buf;
	char		*tmp;

	i = 0;
	ft_putstr("total ");
	while (head)
	{
		tmp = joindir(dir, head->name);
		lstat(tmp, &buf);
		free(tmp);
		i = i + buf.st_blocks;
		head = head->next;
	}
	ft_putnbr(i);
	ft_putchar('\n');
	return (i);
}

void		links_l(t_info *files, char *dir)
{
	int		len;
	char	buff[256];

	dir = joindir(dir, files->file->name);
	if ((len = readlink(dir, buff, sizeof(buff) - 1)) == -1)
	{
		perror("");
		exit(1);
	}
	free(dir);
	buff[len] = '\0';
	ft_putstr(" -> ");
	ft_putstr(buff);
}

void		print_size_device(struct stat buf, t_info *files)
{
	if (file_type(buf.st_mode) != 'c' && file_type(buf.st_mode) != 'b')
	{
		if (files->isdevicefile == 1)
			ft_putstr("       ");
		add_spaces(buf.st_size, files->maxxsize);
		ft_putnbr(buf.st_size);
	}
	else
	{
		add_spaces(devicefile_maj(buf.st_rdev), 3);
		ft_putnbr(devicefile_maj(buf.st_rdev));
		ft_putstr(",");
		add_spaces(buf.st_rdev % 256, 2);
		ft_putnbr(buf.st_rdev % 256);
	}
}
