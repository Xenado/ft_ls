/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_opts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:36:36 by jcaille           #+#    #+#             */
/*   Updated: 2018/03/13 15:49:40 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_opts(char *arg, char opts[NB_OPTS])
{
	int		illegal;
	char	valid_opts[NB_OPTS + 1];
	int		i;

	ft_strcpy(valid_opts, OPTS);
	illegal = 0;
	i = 0;
	if (arg[1])
		while (arg[++i])
		{
			if (ft_strchr(valid_opts, arg[i]))
			{
				if (!ft_strchr(opts, arg[i]))
					ft_strncat(opts, &arg[i], 1);
			}
			else
				illegal = 1;
		}
	else
		opts[0] = '\0';
	return (illegal);
}

void	ft_illegal_opt(char *opts)
{
	char	valid_opts[NB_OPTS + 1];
	int		i;

	ft_strcpy(valid_opts, OPTS);
	i = 1;
	while (opts[i] && ft_strchr(valid_opts, opts[i]))
		i++;
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(opts[i], 2);
	ft_putendl_fd("\nusage: [-lRart] [file ...]\n", 2);
}