/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:42:27 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 14:42:38 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_recup(char **str, t_selectlist **list)
{
	int		i;

	*list = NULL;
	i = 0;
	while (str && str[i])
	{
		*list = ft_addlist(*list, str[i]);
		i++;
	}
	(*list)->curseur = 'y';
	return (i);
}
