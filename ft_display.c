/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:11:57 by jcaille           #+#    #+#             */
/*   Updated: 2018/03/16 14:12:10 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_organize(t_files **files, char opt[NB_OPTS + 1], char *path)
{
	ft_sort_error(files);
	ft_sort_ascii(files, path);
	if (ft_strchr(opt, 't'))
		ft_sort_by_time(files, path);
	if (ft_strchr(opt, 'r'))
		ft_rev_files(files, ft_count_files(files), 
					ft_count_error(files), path);
}

int			ft_display_arg(t_files **files, char opts[NB_OPTS + 1])
{
	t_files		*tmp;
	int			nb_dir;
	t_sizes		*sizes;

	tmp = *files;
	sizes = get_max_sizes(files);
	nb_dir = 0;
	while (tmp)
	{
		if (tmp->error)
		{
			ft_putstr_fd("ft_ls: ", 2);
			ft_putstr_fd(tmp->name, 2);
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(tmp->error, 2);
		}
		else if (tmp->type == 'd')
			nb_dir++;
		else if (ft_strchr(opts, 'l'))
			ft_opt_l(tmp, tmp->name, sizes);
		else
			ft_putendl(tmp->name);
		tmp = tmp->next;
	}
	return (nb_dir);
}

int		ft_display_dir(t_dir **dir, char opts[NB_OPTS + 1])
{
	int		nb_dir;
	char	*tmp_path;
	t_dir	*tmp_dir;
	t_sizes	*sizes;
	t_files *tmp;

	nb_dir = 0;
	tmp_dir = *dir;
	tmp_path = ft_strdup(tmp_dir->path);
	tmp = tmp_dir->files;
	sizes = get_max_sizes(&tmp);
	if (ft_strchr(opts, 'l'))
	{
		ft_putstr("total ");
		ft_putnbr(ft_nblocks(&tmp, opts));
		ft_putchar('\n');
	}
	while (tmp)
	{
		ft_add_path(&tmp_path, tmp->name, (*dir)->path);
		if ((ft_strchr(opts, 'a') && tmp->name[0] == '.') ||
			tmp->name[0] != '.')
		{
			if (tmp->type == 'd')
				nb_dir++;
			if (ft_strchr(opts, 'l'))
				ft_opt_l(tmp, tmp_path, sizes);
			else
				ft_putendl(tmp->name);
		}
		tmp = tmp->next;
	}
	return (nb_dir);
}

void		ft_putnchar(char c, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		ft_putchar(c);
}

void		ft_display_time(t_files *file)
{
	char		*time_st;
	char		*final_time;
	time_t		now;
	char		*str;

	time_st = NULL;
	final_time = NULL;
	now = time(NULL);
	time_st = ctime(&(file->stat->st_mtime));
	final_time = ft_strsub(time_st, 4, 12);
	if (file->stat->st_mtime > now || file->stat->st_mtime < (now - 15778800))
		ft_strcpy(&((char *)final_time)[7], &((char *)time_st)[19]);
	final_time[12] = '\0';
	ft_putchar(' ');
	ft_putstr(final_time);
	ft_putchar(' ');
}
