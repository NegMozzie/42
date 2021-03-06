/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:56:17 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 14:45:24 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int			ft_atoi(char *str)
{
	int		rslt;
	int		s;

	rslt = 0;
	s = 1;
	while (str && (*str == ' ' || *str == '\f' || *str == '\r' || *str == '\v'
		|| *str == '\n' || *str == '\t'))
		str++;
	if (str && *str == '-')
	{
		s = -1;
		str++;
	}
	else if (str && *str == '+')
		str++;
	while (str && *str && ft_isdigit(*str))
		rslt = rslt * 10 + (*str++ - '0');
	return (s * rslt);
}
