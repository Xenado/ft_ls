/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:52:35 by jcaille           #+#    #+#             */
/*   Updated: 2018/03/13 15:49:44 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_check_files(t_files **files, char opts[NB_OPTS + 1])
{
	t_files	*tmp;
	int		nb_dir;

	nb_dir = 0;
	tmp = *files;
	if (!tmp)
		return (-1);
	while (tmp)
	{
		if (tmp->type == 'd')
			nb_dir += 1;
		tmp = tmp->next;
	}
	return (nb_dir);
}

static int		count_args(t_files **args)
{
	t_files		*tmp;
	int			nb_args;

	nb_args = 0;
	if (args)
	{
		tmp = *args;
		while (tmp)
		{
			if (!tmp->error)
				nb_args += 1;
			tmp = tmp->next;
		}
	}
	return (nb_args);
}

static void		display_all(t_files **files, char opts[NB_OPTS + 1], int nb_dir)
{
	t_dir	*dir;
	t_files	*tmp;
	int		nb_args;
	int		file_name;

	tmp = *files;
	nb_args = count_args(files);
	file_name = nb_args > 1 ? 1 : 0;
	if (nb_dir == -1)
	{
		dir = ft_new_dir(".", ".");
		ft_organize(&(dir->files), opts, ".", 0);
		ft_display_ls(dir, opts, 0);
	}
	else
	{
		ft_organize(files, opts, "", 1);
		ft_display_arg(files, opts);
		while (nb_dir && tmp)
		{
			if (tmp->type == 'd')
			{
				dir = ft_new_dir(tmp->name, tmp->name);
				ft_display_ls(dir, opts, file_name);
				free_dir(&dir);
				nb_dir--;
			}
			tmp = tmp->next;
		}
	}
	if (dir)
		free_dir(&dir);
}

int			main(int ac, char **av)
{
	int		i;
	char	opts[NB_OPTS + 1];
	int		illegal_opt;
	t_files	*file;
	t_files	*first_file;

	i = 0;
	illegal_opt = 0;
	ft_bzero((void *)opts, 6);
	while (++i < ac && av[i][0] == '-' && av[i][1] && ft_strcmp(av[i], "--"))
		if ((illegal_opt = ft_check_opts(av[i], opts)))
			ft_illegal_opt(av[i]);
	if (illegal_opt)
		exit(0);
	first_file = NULL;
	if (i < ac)
		first_file = ft_new_file(av[i], av[i]);
	file = first_file;
	while (++i < ac)
	{
		file->next = ft_new_file(av[i], av[i]);
		file = file->next;
	}
	display_all(&first_file, opts, ft_check_files(&first_file, opts));
	free_files(first_file);
	while(1);
	return (0);
}