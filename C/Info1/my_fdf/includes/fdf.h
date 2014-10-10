/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:14:37 by msarr             #+#    #+#             */
/*   Updated: 2014/10/08 18:21:50 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_coord
{
	float			x;
	float			y;
	float			z;
}				t_coord;

typedef	struct	s_env
{
	void		*ptr;
	void		*win;
	char		*file;
	t_coord		**tab;
}				t_env;

int			transform(t_coord **tab, int pad);
int			init(t_env *env);
void		fake_expose(t_env env);


#endif