/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_symln.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:42:59 by jcaille           #+#    #+#             */
/*   Updated: 2018/03/12 16:52:27 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	DIR				*dirp;
	struct dirent	*dp;
	ssize_t			nb_car;
	char			buf[256];

	dirp = opendir(av[1]);
	if (!dirp)
	{
		if (errno == 20)
			ft_putendl(av[1]);
		else
			perror(av[1]);
	}
	else
	{
		while ((dp = readdir(dirp)))
		{
			if (dp->d_type == DT_LNK)
			{
				ft_putendl(dp->d_name);
				nb_car = readlink(dp->d_name, buf, 255);
				buf[nb_car] = '\0';
				ft_putendl(buf);
			}
		}
		(void)closedir(dirp);
	}
	return (0);
}
