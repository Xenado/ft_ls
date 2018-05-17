/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:44:18 by jcaille           #+#    #+#             */
/*   Updated: 2018/03/14 17:44:23 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_swap_data(t_files **files, char *path)
{
	t_files			*tmp;
	char			name_tmp[256];
	char			type_tmp;
	char			*tmp_path;

	tmp = *files;
	tmp_path = NULL;
	if (ft_strcmp(path, "."))
		ft_add_path(&tmp_path, tmp->name, path);
	else
		tmp_path = ft_strdup(tmp->name);
	lstat(tmp_path, tmp->next->stat);
	if (ft_strcmp(path, "."))
		ft_add_path(&tmp_path, tmp->next->name, path);
	else
		tmp_path = ft_strdup(tmp->next->name);
	lstat(tmp_path, tmp->stat);
	ft_strcpy(name_tmp, tmp->name);
	ft_strcpy(tmp->name, tmp->next->name);
	ft_strcpy(tmp->next->name, name_tmp);
	type_tmp = tmp->type;
	tmp->type = tmp->next->type;
	tmp->next->type = type_tmp;
}

void			ft_sort_ascii(t_files **begin_file, char *path)
{
	t_files		*tmp;
	int			sort;

	sort = 1;
	if (*begin_file)
		while (sort)
		{
			tmp = *begin_file;
			sort = 0;
			while (tmp->next)
			{
				if (ft_strcmp(tmp->name, tmp->next->name) > 0 && !(tmp->error))
				{
 					ft_swap_data(&tmp, path);
					sort = 1;
				}
				tmp = tmp->next;
			}
		}
}

void			ft_sort_by_time(t_files **begin_file, char *path)
{
	t_files		*tmp;
	int			sort;

	sort = 1;
	if (*begin_file)
	{
		while (sort)
		{
			tmp = *begin_file;
			sort = 0;
			while (tmp->next)
			{
				if (tmp->stat->st_mtime < tmp->next->stat->st_mtime
					&& !(tmp->error))
				{
					ft_swap_data(&tmp, path);
					sort = 1;
				}
				tmp = tmp->next;
			}
		}
	}
}

static void		ft_swap_error(t_files **files, int *sort, int tri_ascii)
{
	t_files			*tmp;
	char			name_tmp[256];

	tmp = *files;
	*sort = 1;
	if (!(tmp->error) && tmp->next->error && !tri_ascii)
	{
		tmp->error = ft_strdup(tmp->next->error);
		free(tmp->next->error);
		tmp->next->error = NULL;
		ft_strcpy(name_tmp, tmp->name);
		ft_strcpy(tmp->name, tmp->next->name);
		ft_strcpy(tmp->next->name, name_tmp);
		tmp->next->type = tmp->type;
		tmp->type = '\0';
		lstat(tmp->next->name, tmp->next->stat);
	}
	if (tmp->error && tmp->next->error
		&& ft_strcmp(tmp->name, tmp->next->name) > 0 && tri_ascii)
	{
		ft_strcpy(name_tmp, tmp->name);
		ft_strcpy(tmp->name, tmp->next->name);
		ft_strcpy(tmp->next->name, name_tmp);
	}
}

void			ft_sort_error(t_files **files)
{
	t_files		*tmp;
	int			sort;

	sort = 1;
	while (sort)
	{
		tmp = *files;
		sort = 0;
		while (tmp->next)
		{
			if (!(tmp->error) && tmp->next->error)
				ft_swap_error(&tmp, &sort, 0);
			tmp = tmp->next;
		}
		tmp = *files;
		while (tmp->next)
		{
			if (tmp->error && tmp->next->error
				&& ft_strcmp(tmp->name, tmp->next->name) > 0)
				ft_swap_error(&tmp, &sort, 1);
			tmp = tmp->next;
		}
	}
}
