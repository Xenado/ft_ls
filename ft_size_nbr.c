/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:53:45 by jcaille           #+#    #+#             */
/*   Updated: 2018/03/20 17:53:56 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		size_int(int n)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

int		ft_nlink_max(t_files **files)
{
	t_files		*file;
	int			size_max;
	int			size_nbr;

	file = *files;
	size_max = 0;
	while (file)
	{
		if (!file->error)
		{
			size_nbr = size_int((int)file->stat->st_nlink);
			if (size_nbr > size_max)
				size_max = size_nbr;
		}
		file = file->next;
	}
	return (size_max);
}

int		ft_size_max(t_files **files)
{
	t_files		*file;
	int			size_max;
	int			size_nbr;

	file = *files;
	size_max = 0;
	while (file)
	{
		if (!file->error && file->type != 'c' && file->type != 'b' &&
			file->type != 's')
		{
			size_nbr = size_int((int)file->stat->st_size);
			if (size_nbr > size_max)
				size_max = size_nbr;
		}
		file = file->next;
	}
	return (size_max);
}

int		ft_size_max_maj(t_files **files)
{
	t_files		*file;
	int			size_major;
	int			size_max;

	file = *files;
	size_max = 0;
	while (file)
	{
		if (!file->error && (file->type == 'c' || file->type == 'b' ||
			file->type == 's'))
		{
			size_major = size_int((int)major(file->stat->st_rdev));
			if (size_major > size_max)
				size_max = size_major;
		}
		file = file->next;
	}
	return (size_max);
}

int		ft_size_max_min(t_files **files)
{
	t_files		*file;
	int			size_max;
	int			size_minor;

	file = *files;
	size_max = 0;
	while (file)
	{
		if (!file->error && (file->type == 'c' || file->type == 'b' ||
			file->type == 's'))
		{
			size_minor = size_int((int)major(file->stat->st_rdev));
			if (size_minor > size_max)
				size_max = size_minor;
		}
		file = file->next;
	}
	return (size_max);
}
