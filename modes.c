/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:31:37 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/01 14:16:16 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define SETUID (st_mode & S_IXUSR) ? PT('s') : PT('S')
#define UX (st_mode & S_IXUSR) ? PT('x') : PT('-')
#define PT(x) ft_putchar(x)
#define GX (st_mode & S_IXGRP) ? PT('x') : PT('-')
#define SETGID (st_mode & S_IXGRP) ? PT('s') : PT('S')
#define STICKY ((st_mode & S_IXOTH) ? PT('t') : PT('T'))
#define OX (st_mode & S_IXOTH) ? PT('x') : PT('-')

char	file_type(mode_t st_mode)
{
	if ((st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	if ((st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	if ((st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	if ((st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	if ((st_mode & S_IFMT) == S_IFREG)
		return ('-');
	if ((st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	if ((st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	return ('?');
}

int		permissions(mode_t st_mode, char *filename)
{
	acl_t pp;

	(st_mode & S_IRUSR) ? PT('r') : PT('-');
	(st_mode & S_IWUSR) ? PT('w') : PT('-');
	(st_mode & S_ISUID) ? SETUID : (UX);
	(st_mode & S_IRGRP) ? PT('r') : PT('-');
	(st_mode & S_IWGRP) ? PT('w') : PT('-');
	(st_mode & S_ISGID) ? SETGID : GX;
	(st_mode & S_IROTH) ? PT('r') : PT('-');
	(st_mode & S_IWOTH) ? PT('w') : PT('-');
	(st_mode & S_ISVTX) ? STICKY : OX;
	if (listxattr(filename, NULL, 0, XATTR_NOFOLLOW) > 0)
		PT('@');
	else if ((pp = acl_get_link_np(filename, ACL_TYPE_EXTENDED)) != NULL)
	{
		acl_free((void *)pp);
		PT('+');
	}
	else
		ft_putstr(" ");
	return (0);
}

char	permcheck(char *filepath)
{
	struct stat	buf;

	lstat(filepath, &buf);
	return (((buf.st_mode & S_IRUSR) || (buf.st_mode & S_IRGRP)
				|| (buf.st_mode & S_IROTH)) ? 'r' : '-');
}

char	permcheck_l(char *filepath)
{
	struct stat	buf;

	lstat(filepath, &buf);
	return (((buf.st_mode & S_IRUSR) && (buf.st_mode & S_IRGRP)
				&& (buf.st_mode & S_IROTH)) ? 'r' : '-');
}
