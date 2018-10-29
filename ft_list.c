/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:13:16 by jcaille           #+#    #+#             */
/*   Updated: 2018/03/14 12:13:24 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	ft_check_type(mode_t st_mode)
{
	char	type;

	if (S_ISREG(st_mode))
		type = '-';
	else if (S_ISDIR(st_mode))
		type = 'd';
	else if (S_ISLNK(st_mode))
		type = 'l';
	else if (S_ISCHR(st_mode))
		type = 'c';
	else if (S_ISBLK(st_mode))
		type = 'b';
	else if (S_ISFIFO(st_mode))
		type = 'p';
	else if (S_ISSOCK(st_mode))
		type = 's';
	return (type);
}

t_files		*ft_new_file(char *file_name, char *path)
{
	t_files		*file;

	if (!(file = (t_files *)malloc(sizeof(t_files))))
		return (NULL);
	ft_strcpy(file->name, file_name);
	if (!(file->stat = (struct stat *)malloc(sizeof(struct stat))))
		return (NULL);
	if ((lstat(path, file->stat)) == -1)
	{
		file->error = ft_strdup(strerror(errno));
		file->type = '\0';
	}
	else
	{
		file->error = NULL;
		file->type = ft_check_type(file->stat->st_mode);
	}
	file->next = NULL;
	return (file);
}

t_dir		*ft_new_dir(char *dir_name, char *path)
{
	t_dir	*dir;
	char	*tmp;

	if (!(dir = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	tmp = ft_strdup(path);
	ft_strcpy(dir->name, dir_name);
	if (ft_strcmp(dir_name, path))
		ft_add_path(&tmp, dir_name, path);
	dir->files = ft_rd_dir(tmp);
	dir->path = ft_strdup(tmp);
	free(tmp);
	dir->next = NULL;
	return (dir);
}

void		free_files(t_files *file)
{
	t_files		*tmp;
	t_files		*next;

	tmp = file;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->stat);
		if (tmp->error)
			free(tmp->error);
		free(tmp);
		tmp = next;
	}
	file = NULL;
}

void		free_dir(t_dir **dir)
{
	t_dir	*tmp;
	t_dir	*next;

	tmp = *dir;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->files)
			free_files(tmp->files);
		if (tmp->path)
			free(tmp->path);
		free(tmp);
		tmp = next;
	}
	*dir = NULL;
}
