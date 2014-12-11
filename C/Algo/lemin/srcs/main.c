/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/12/10 19:19:48 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "fdf.h"

int					hash(char *str)
{
	int				code;
	int				len;
	int				i;

	len = ft_strlen(str);
	code = 7;
	i = 0;
	while (i < len)
	{
		code = str[i] + 31 * code;
		i++;
	}
	return (code % 1000);
}
void		put_link(t_room *room)
{
	t_link	*l;

	l = room->lst;
	while (l)
	{
		ft_putstr(l->room->name);
		ft_putstr("->");
		l = l->next;
	}
	ft_putendl(NULL);
}

int					main(int argc, char **argv)
{
	t_lem			*lem;
	t_env			env;

	if ((lem = parse()))
	{
		lem->end->dist = 0;
		if (argc == 2 && !ft_strcmp(argv[1], "-g"))
			lem->g = 1;
		else
			lem->g = 0;
		lem->start->lem = 1;
		way(lem->end, lem);
		sort(lem->tab);
		if (lem->start->dist < 1000)
		{
			if (lem->g)
			{
				init(&env, lem);
				fdf(env);
			}
			else
				lemin(lem);
			return (0);
		}
	}
	ft_putstr("ERROR\n");
	return (0);
}
