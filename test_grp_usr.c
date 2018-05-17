/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_grp_usr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:26:34 by jcaille           #+#    #+#             */
/*   Updated: 2018/02/26 16:00:21 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	struct stat		*bufstat;
	struct passwd	*bufpwd;
	struct group	*bufgrp;

	bufstat = malloc(sizeof(struct stat));
	lstat(av[1], bufstat);
	bufpwd = getpwuid(bufstat->st_uid);
	bufgrp = getgrgid(bufstat->st_gid);
	ft_putendl(bufpwd->pw_name);
	ft_putstr(bufgrp->gr_name);
	return (0);
}
