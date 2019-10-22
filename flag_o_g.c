/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o_g.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:47:36 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/10/02 22:53:38 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	store_flag_og(char arg, char *tr_flag, int *j)
{
	if ((arg == '1') && ft_strchr(tr_flag, 'l'))
		*ft_strchr(tr_flag, 'l') = '1';
	if ((arg == '1') && ft_strchr(tr_flag, 'o'))
		*ft_strchr(tr_flag, 'o') = '1';
	if ((arg == '1') && ft_strchr(tr_flag, 'g'))
		*ft_strchr(tr_flag, 'g') = '1';
	else
		tr_flag[(*j)++] = arg;
}

void	print_o_g(t_info *files, struct passwd *passwd, struct group *group)
{
	if (files->isflagg == 0)
	{
		add_spaces(9, 0);
		ft_putstr(passwd->pw_name);
		add_spaces(0, files->maxxpw_name - ft_strlen(passwd->pw_name) - 1);
	}
	if (files->isflago == 0)
	{
		if (files->isflagg == 0)
			add_spaces(0, 1);
		else
			ft_putchar(' ');
		ft_putstr(group->gr_name);
	}
}
