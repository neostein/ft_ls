/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_flag_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:03:15 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/09/29 23:03:28 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	mtimenewline(__darwin_time_t times)
{
	char	*string;
	int		index;
	int		end;
	time_t	now;

	index = 0;
	end = 0;
	now = 0;
	string = ctime(&times);
	while (string[now++] != '\n')
	{
		if (string[now - 1] == ' ' && index == 0)
			index = now;
		if (string[now - 1] == ':')
			end = now - 2;
	}
	print_time(index, end, times, string);
}

void	add_spaces(int nbr, int maxint)
{
	int n;

	n = ft_intlen(nbr);
	while (((maxint + 2) - n) > 0)
	{
		ft_putstr(" ");
		n++;
	}
}

int		maxxstr(char *str, t_nmfile *head, char *dir)
{
	t_itmp			value;
	struct stat		buf;
	struct passwd	*passwd;
	struct group	*group;
	char			*tmp2;

	value.j = 0;
	while (head)
	{
		tmp2 = joindir(dir, head->name);
		lstat(tmp2, &buf);
		free(tmp2);
		passwd = getpwuid(buf.st_uid);
		group = getgrgid(buf.st_gid);
		if (!ft_strcmp(str, "pw_name"))
			value.i = ft_strlen(passwd->pw_name);
		else
			value.i = ft_strlen(group->gr_name);
		if (value.i > value.j)
			value.j = value.i;
		head = head->next;
	}
	return (value.j);
}

int		maxxint(char *str, t_nmfile *head, char *dir)
{
	int			maxint;
	int			value;
	struct stat buf;
	char		*tmp;

	maxint = 0;
	while (head)
	{
		tmp = joindir(dir, head->name);
		lstat(tmp, &buf);
		if (!ft_strcmp(str, "size"))
			(value = buf.st_size);
		else
			value = buf.st_nlink;
		if (value > maxint)
			maxint = value;
		free(tmp);
		head = head->next;
	}
	return (ft_intlen(maxint));
}

void	print_time(int index, int end, time_t times, char *string)
{
	time_t	now;

	time(&now);
	while (index <= end - 6 + (times > now ? 0 : 1))
		ft_putchar(string[index++]);
	while (times < (now - 15758458) && string[end + 4] != '\n')
		ft_putchar(string[end++ + 4]);
	if (times > now)
	{
		while (string[end++ + 4] != ' ')
			ft_putchar(string[end + 3]);
		ft_putstr("  ");
		while (string[++end + 3] != '\n')
			if (string[end + 3] != ' ')
				ft_putchar(string[end + 3]);
	}
	while (index <= end && !(times < (now - 15758458)) && !(times > now))
		ft_putchar(string[index++]);
}
