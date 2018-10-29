/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rd_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:22:32 by jcaille           #+#    #+#             */
/*   Updated: 2018/03/14 13:22:43 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_files	*rd_dir(DIR *dirp, char **path, char *dir_name)
{
	t_files			*begin;
	t_files			*file;
	struct dirent	*dp;

	begin = NULL;
	dp = readdir(dirp);
	ft_add_path(path, dp->d_name, dir_name);
	begin = ft_new_file(dp->d_name, *path);
	file = begin;
	while ((dp = readdir(dirp)))
	{
		ft_add_path(path, dp->d_name, dir_name);
		file->next = ft_new_file(dp->d_name, *path);
		file = file->next;
	}
	(void)closedir(dirp);
	return (begin);
}

void			ft_add_path(char **path, char *file_name, char *dir_name)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(dir_name) + ft_strlen(file_name) + 1);
	ft_strcpy(tmp, dir_name);
	ft_strcat(tmp, "/");
	ft_strcat(tmp, file_name);
	if (*path)
		free(*path);
	*path = ft_strdup(tmp);
	free(tmp);
}

t_files			*ft_rd_dir(char *dir_name)
{
	t_files			*file;
	DIR				*dirp;
	char			*path;

	path = ft_strdup(dir_name);
	dirp = opendir(dir_name);
	file = NULL;
	if (dirp)
		file = rd_dir(dirp, &path, dir_name);
	else
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(dir_name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	if (path)
		free(path);
	return (file);
}

struct passwd	*ft_get_uid(t_files *file)
{
	struct passwd	*bufpwd;

	bufpwd = getpwuid(file->stat->st_uid);
	return (bufpwd);
}

struct group	*ft_get_gid(t_files *file)
{
	struct group	*bufgrp;

	bufgrp = getgrgid(file->stat->st_gid);
	return (bufgrp);
}
