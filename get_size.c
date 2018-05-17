/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 09:50:19 by jcaille           #+#    #+#             */
/*   Updated: 2018/04/20 09:50:23 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_size_uid(t_files **files)
{
	t_files			*file;
	int				size_max;
	int				size;
	struct passwd	*pwd;

	file = *files;
	size_max = 0;
	while (file)
	{
		pwd = ft_get_uid(file);
		size = ft_strlen(pwd->pw_name);
		if (size > size_max)
			size_max = size;
		file = file->next;
	}
	return (size_max);
}

int		get_size_gid(t_files **files)
{
	t_files			*file;
	int				size_max;
	int				size;
	struct group	*grp;

	file = *files;
	size_max = 0;
	while (file)
	{
		grp = ft_get_gid(file);
		size = ft_strlen(grp->gr_name);
		if (size > size_max)
			size_max = size;
		file = file->next;
	}
	return (size_max);
}

t_sizes	*get_sizes(t_files *file)
{
	t_sizes			*sizes;
	struct passwd	*pwd;
	struct group	*grp;

	pwd = ft_get_uid(file);
	grp = ft_get_gid(file);
	if (!(sizes = (t_sizes *)malloc(sizeof(t_sizes))))
		return (NULL);
	sizes->size_ln = size_int((int)file->stat->st_nlink);
	sizes->size_uid = ft_strlen(pwd->pw_name);
	sizes->size_gid = ft_strlen(grp->gr_name);
	if (file->type == 'c' || file->type == 'b' || file->type == 's')
	{
		sizes->size_minor = size_int((int)minor(file->stat->st_rdev));
		sizes->size_major = size_int((int)major(file->stat->st_rdev));
		sizes->size_file = 0;
	}
	else
	{
		sizes->size_minor = 0;
		sizes->size_major = 0;
		sizes->size_file = size_int((int)file->stat->st_size);
	}
	return (sizes);
}

t_sizes	*get_max_sizes(t_files **files)
{
	t_sizes	*sizes;

	sizes = NULL;
	if (*files)
	{
		if (!(sizes = (t_sizes *)malloc(sizeof(t_sizes))))
			return (NULL);
		sizes->size_ln = ft_nlink_max(files);
		sizes->size_uid = get_size_uid(files);
		sizes->size_gid = get_size_gid(files);
		sizes->size_minor = ft_size_max_min(files);
		sizes->size_major = ft_size_max_maj(files);
		sizes->size_file = ft_size_max(files);
	}
	return (sizes);
}

int		ft_nblocks(t_files **files, char opts[NB_OPTS + 1])
{
	t_files		*file;
	int			nb_block;

	nb_block = 0;
	file = *files;
	while (file)
	{
		if ((ft_strchr(opts, 'a') && file->name[0] == '.') ||
			file->name[0] != '.')
			nb_block += (int)file->stat->st_blocks;
		file = file->next;
	}
	return (nb_block);
}