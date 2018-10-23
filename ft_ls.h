/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:48:22 by jcaille           #+#    #+#             */
/*   Updated: 2018/03/13 15:49:50 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include <sys/acl.h>
# include <errno.h>

# define OPTS "lRart"
# define NB_OPTS 5

typedef struct		s_files
{
	char			name[256];
	char			*error;
	char			type;
	struct stat		*stat;
	struct s_files	*next;
}					t_files;

typedef struct		s_dir
{
	char			name[256];
	char			*path;
	t_files			*files;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_sizes
{
	int				size_ln;
	int				size_uid;
	int				size_gid;
	int				size_file;
	int				size_major;
	int				size_minor;
}					t_sizes;

int					ft_check_opts(char *arg, char opts[NB_OPTS + 1]);
void				ft_illegal_opt(char *opts);

t_files				*ft_rd_dir(char *dir_name);
void				ft_add_path(char **path, char *file_name, char *dir_name);

t_files				*ft_new_file(char *file_name, char *path);
t_dir				*ft_new_dir(char *dir_name, char *path);
void				free_files(t_files **file);
void				free_dir(t_dir **dir);

void				ft_swap_data(t_files **files, char *path);
void				ft_sort_ascii(t_files **begin_file, char *path, int arg);
void				ft_sort_by_time(t_files **begin_file, char *path, int arg);
void				ft_sort_error(t_files **files);

int					ft_count_error(t_files **begin_file);
int					ft_count_files(t_files **files);
void				ft_rev_files(t_files **begin_file, int nb_files, int nb_error, 
								char *path, int arg);

void				ft_organize(t_files **files, char opt[NB_OPTS + 1], char *path, int arg);
int					ft_display_arg(t_files **files, char opts[NB_OPTS + 1]);
int					ft_display_dir(t_dir **dir, char opts[NB_OPTS + 1]);
void				ft_putnchar(char c, int n);
void				ft_display_time(t_files *file);

int					size_int(int n);
int					ft_nlink_max(t_files **files);
int					ft_size_max(t_files **files);
int					ft_size_max_maj(t_files **files);
int					ft_size_max_min(t_files **files);

int					get_size_uid(t_files **files);
int					get_size_gid(t_files **files);
t_sizes				*get_sizes(t_files *file);
t_sizes				*get_max_sizes(t_files **files);
int					ft_nblocks(t_files **files, char opts[NB_OPTS + 1]);

void				ft_opt_l(t_files *file, char *path, t_sizes *sizes_max);
struct passwd		*ft_get_uid(t_files *file);
struct group		*ft_get_gid(t_files *file);

int					ft_display_ls(t_dir *dir, char opts[NB_OPTS + 1], int d_name);
int 				ft_check_dir(t_dir *dir, char opts[NB_OPTS + 1]);

#endif
