/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:07:23 by jcaille           #+#    #+#             */
/*   Updated: 2018/03/20 16:38:20 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_perm(t_files *file, char *path)
{
	char		perm[12];
	acl_t		acl;
	ssize_t		xattr;

	ft_bzero((void *)perm, 12);
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	perm[0] = file->type;
	perm[1] = (file->stat->st_mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (file->stat->st_mode & S_IWUSR) ? 'w' : '-';
	perm[3] = (file->stat->st_mode & S_IXUSR) ? 'x' : '-';
	perm[4] = (file->stat->st_mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (file->stat->st_mode & S_IWGRP) ? 'w' : '-';
	perm[6] = (file->stat->st_mode & S_IXGRP) ? 'x' : '-';
	perm[7] = (file->stat->st_mode & S_IROTH) ? 'r' : '-';
	perm[8] = (file->stat->st_mode & S_IWOTH) ? 'w' : '-';
	perm[9] = (file->stat->st_mode & S_IXOTH) ? 'x' : '-';
	if (xattr > 0)
		perm[10] = '@';
	else if (acl != NULL)
		perm[10] = '+';
	else
		perm[10] = ' ';
	ft_putstr(perm);
}

void			ft_opt_l(t_files *file, char *path, t_sizes *sizes_max)
{
	t_sizes			*sizes;
	struct passwd	*pwd;
	struct group	*grp;
	ssize_t			nb_car;
	char			buf[256];

	sizes = get_sizes(file);
	pwd = ft_get_uid(file);
	grp = ft_get_gid(file);
	ft_perm(file, path);
	ft_putnchar(' ', 1 + sizes_max->size_ln - sizes->size_ln);
	ft_putnbr((int)file->stat->st_nlink);
	ft_putchar(' ');
	ft_putstr(pwd->pw_name);
	ft_putnchar(' ', 2 + sizes_max->size_uid - sizes->size_uid);
	ft_putstr(grp->gr_name);
	if (sizes->size_major)
	{
		ft_putnchar(' ', 3 + sizes_max->size_major + sizes_max->size_gid -\
					sizes->size_major - sizes->size_gid);
		ft_putnbr((int)major(file->stat->st_rdev));
		ft_putstr(", ");
		ft_putnchar(' ', 1 + sizes_max->size_minor - sizes->size_minor);
		ft_putnbr((int)minor(file->stat->st_rdev));
	}
	else if (sizes_max->size_major)
	{
		ft_putnchar(' ', 6 + sizes_max->size_major + sizes_max->size_minor +\
					sizes_max->size_gid - sizes->size_file - sizes->size_gid);
		ft_putnbr((int)file->stat->st_size);
	}
	else
	{
		ft_putnchar(' ', 2 + sizes_max->size_file + sizes_max->size_gid -\
					sizes->size_file - sizes->size_gid);
		ft_putnbr((int)file->stat->st_size);
	}
	ft_display_time(file);
	if (file->type != 'l')
		ft_putendl(file->name);
	else
	{
		ft_putstr(file->name);
		nb_car = readlink(path, buf, 255);
		buf[nb_car] = '\0';
		ft_putstr(" -> ");
		ft_putendl(buf);
	}
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
