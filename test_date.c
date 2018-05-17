/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_date.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:21:05 by jcaille           #+#    #+#             */
/*   Updated: 2018/02/26 15:12:05 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	struct stat	*bufstat;
	char		*time_st = NULL;
	char		*final_time = NULL;
	int			i;
	time_t		now;

	now = time(NULL);
	bufstat = malloc(sizeof(struct stat));
	i = lstat(av[1], bufstat);
	if (i != 0)
		perror(av[1]);
	else
	{
		time_st = ctime(&(bufstat->st_mtime));
		final_time = ft_strsub(time_st, 4, 12);
		if (bufstat->st_mtime > now || bufstat->st_mtime < (now - 15778800))
			ft_strcpy(&((char *)final_time)[7], &((char *)time_st)[19]);
		ft_putstr(final_time);
	}
	return (0);
}
