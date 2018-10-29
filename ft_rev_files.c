/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:06:24 by jcaille           #+#    #+#             */
/*   Updated: 2018/03/20 16:06:30 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_organize(t_files **files, char opt[NB_OPTS + 1], char *path,
						int arg)
{
	ft_sort_error(files);
	ft_sort_ascii(files, path, arg);
	if (ft_strchr(opt, 't'))
		ft_sort_by_time(files, path, arg);
	if (ft_strchr(opt, 'r'))
		ft_rev_files(files, ft_count_error(files), path, arg);
}

int			ft_count_error(t_files **begin_file)
{
	t_files		*tmp;
	int			nb_error;

	nb_error = 0;
	tmp = *begin_file;
	while (tmp && tmp->error)
	{
		nb_error++;
		tmp = tmp->next;
	}
	return (nb_error);
}

int			ft_count_files(t_files **files)
{
	t_files	*tmp;
	int		nb_files;

	tmp = *files;
	nb_files = 0;
	while (tmp)
	{
		nb_files++;
		tmp = tmp->next;
	}
	return (nb_files);
}

void		ft_rev_files(t_files **begin_file, int nb_error, char *path,
							int arg)
{
	int			i;
	int			i2;
	t_files		*tmp;
	t_files		*tmp_start;
	int			nb_files;

	i = -1;
	nb_files = ft_count_files(begin_file);
	tmp_start = *begin_file;
	while (++i < nb_error)
		tmp_start = tmp_start->next;
	while (++i < nb_files)
	{
		tmp = tmp_start;
		i2 = 0;
		while (i2 < nb_files - i)
		{
			if (arg)
				ft_swap_data(&tmp, tmp->name);
			else
				ft_swap_data(&tmp, path);
			tmp = tmp->next;
			i2++;
		}
	}
}
