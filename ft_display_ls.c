/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:15:35 by jcaille           #+#    #+#             */
/*   Updated: 2018/05/17 11:15:45 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	ft_check_dir(t_dir *dir, char opts[NB_OPTS + 1])
{
	t_files		*tmp;
	int			nb_dir;

	nb_dir = 0;
	tmp = dir->files;
	while (tmp)
	{
		if (tmp->type == 'd' && ((ft_strchr(opts, 'a') && tmp->name[0] == '.')
			|| tmp->name[0] != '.'))
			nb_dir += 1;
		tmp = tmp->next;
	}
	return (nb_dir);
}

int		ft_display_ls(t_dir *dir, char opts[NB_OPTS + 1], int d_name)
{
	int		nb_dir;
	t_files	*tmp;

	tmp = dir->files;
	nb_dir = ft_check_dir(dir, opts);
	if(d_name)
	{
		ft_putstr(dir->path);
		ft_putendl(":");
	}
	ft_organize(&(dir->files), opts, (dir->path), 0);
	ft_display_dir(&dir, opts);
	if (ft_strchr(opts, 'R'))
		while (nb_dir)
		{
			if (tmp->type == 'd' && ((ft_strchr(opts, 'a') &&
				tmp->name[0] == '.') || tmp->name[0] != '.'))
			{
				ft_putchar('\n');
				nb_dir -= 1;
				dir->next = ft_new_dir(tmp->name, dir->path);
				ft_putendl("-------------------ft_new_dir-------------------");
				if (ft_display_ls(dir->next, opts, 1))
					return (nb_dir);
			}
			tmp = tmp->next;
		}
	return (0);
}