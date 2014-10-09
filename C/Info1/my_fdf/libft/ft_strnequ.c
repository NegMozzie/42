/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:12:17 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 15:55:48 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_strnequ(const char *s1, const char *s2, size_t n)
{
	while (s1 && s2 && *s1 && *s2 && *s1 == *s2 && n--)
	{
		if (!n)
			return (1);
		s1++;
		s2++;
	}
	if (s1 && s2 && !(*s1) && !(*s2))
		return (1);
	else
		return (0);
}
