/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 14:01:29 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 15:07:48 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSFT_H
# define LSFT_H

# include <unistd.h>
# include <stdio.h>
# include <dirent.h>
# include <string.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <sys/types.h>
# include <time.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include "libft.h"

typedef struct			s_dirlist
{
	char				*str;
	time_t				atime;
	struct s_dirlist	*next;
}						t_dirlist;

typedef struct			s_dir
{
	t_dirlist			*dir;
	int					recursive;
	int					infos;
	int					sort_type;
	int					sort_mod;
	int					hiden;
	int					error;
}						t_dir;

void					ft_perror(char *str);
t_dirlist				*ft_addlist(t_dirlist *list, char *str, time_t atime);
void					ft_putattr(struct stat sb);
t_dirlist				*ft_getdirlist(char *dir, t_dir *test);
t_dirlist				*ft_arecupdir(char *dir);
t_dirlist				*ft_sortlist(t_dirlist *list, int i, int j);
void					ft_ls(char *line, t_dir *dir);
void					ft_put_s(const char *s);
void					ft_acceserror(char *str, char **argv, int argc);
void					ft_putdir(char *str, t_dir *dir, struct stat test);
t_dirlist				*ft_delelmt(t_dirlist *list);
void					ft_putinfos(struct stat test);
t_dir					*ft_parse(int argc, char **argv);

#endif
