/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:23:32 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/03 19:29:43 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct		s_nmfile
{
	char			*name;
	time_t			mtime;
	long			mtimenano;
	struct s_nmfile	*next;

}					t_nmfile;

typedef struct		s_info
{
	struct s_nmfile *file;
	struct s_nmfile *dir;
	struct s_nmfile *unkn;
	struct s_nmfile *head;
	int				isdevicefile;
	int				isflago;
	int				isflagg;
	int				maxxnlink;
	int				maxxpw_name;
	int				maxxgr_name;
	int				maxxsize;

}					t_info;

typedef struct		s_itmp
{
	int				i;
	int				j;
}					t_itmp;

typedef struct		s_lsread
{
	DIR				*dirp;
	struct dirent	*dp;
}					t_lsread;

void				store_files(char *name, t_info *files, char *flags);
char				file_type(mode_t st_mode);
int					permissions(mode_t st_mode, char *path);
char				*store_flags(char *flag);
void				no_flags(t_info *files);
void				normal_sort(t_nmfile **files);
void				flags_only(char *flags, t_info *files);
int					unknown_files(t_nmfile *files);
int					parsing(char *av, t_info *files, char **flags);
t_nmfile			*listnew(char *name, struct stat *info);
void				listadd(t_nmfile **head, t_nmfile *new);
void				bubble_sort(t_nmfile **files);
void				flag_capr(t_lsread ls, t_info *files,
					int d, char *path, char *flags, int k);
void				flag_a(t_info *files, char *flags, char *dir);
void				flag_wa(t_info *files, char *flags, char *dir);
int					flag_l(t_info *files,
					char *flags, struct stat buf, char *dir);
void				bubble_sort_time(t_nmfile **files);
void				bubble_sort_rev(t_nmfile **files);
void				bubble_sort_time_rev(t_nmfile **files);
void				mtimenewline(__darwin_time_t times);
int					maxxint(char *str, t_nmfile *head, char *dir);
int					maxxstr(char *str, t_nmfile *head, char *dir);
void				add_spaces(int nbr, int maxint);
int					std_print(t_nmfile *files);
int					ft_intlen(int n);
int					totalsum(t_nmfile *head, char *dir);
char				permcheck(char *filepath);
int					devicefile_maj(dev_t bufst_dev);
void				sorting(t_info *new_files, char *flags);
void				links_l(t_info *files, char *dir);
void				print_size_device(struct stat buf, t_info *files);
char				*joindir(char *dir, char *file);
void				init_ldata(t_info *files, char *dir);
void				no_permission(char *dir);
void				no_flags_dir(t_nmfile *files, t_nmfile *dir);
void				with_flags_capr(t_info *files, char *flags);
void				prep_l(t_info *files, char *dir, char *flags, int k);
void				listfree(t_nmfile *file);
void				listalloc(t_info **new_files);
void				no_args(t_info *files);
int					first_print(t_info *argfiles, char *flags);
void				print_foldername(char *name);
void				flags_files(t_info *argfiles, t_info *files, char *flags);
int					listcount(t_nmfile *file);
char				*print_capr_dir(t_itmp dk, char *path, char *dir);
void				flag_capr2(t_info *files,
					char *path, char *flags, t_itmp dk);
int					prep_capr(char *dir, char *flags,
					t_info *new_files, t_itmp dk);
void				flags_files_nocapr(t_info *argfiles,
					t_info *files, char *flags, t_itmp dk);
void				illegal_option(char flag);
void				flg_files_nocapr_print(t_itmp *dk,
					char *flags, t_info *argfiles, t_info *files);
t_nmfile			*listnew_noflags(char *name);
void				no_flags_dir_print(int dir_count,
					t_nmfile *dir, t_nmfile *file, t_lsread ls);
void				print_time(int index, int end, time_t times, char *string);
char				permcheck_l(char *filepath);
void				error_perm(char *dir);
void				store_flag_og(char arg, char *tr_flag, int *j);
void				print_o_g(t_info *files,
					struct passwd *passwd, struct group *group);
#endif
