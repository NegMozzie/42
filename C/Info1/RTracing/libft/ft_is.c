/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 14:38:27 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/15 14:38:35 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int				ft_is(char *str, int c)
{
	int			i;

	i = 0;
	while (str && *str)
	{
		if (*str == c)
			return (i);
		str++;
		i++;
	}
	return (0);
}
