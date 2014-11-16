/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 15:08:25 by msarr             #+#    #+#             */
/*   Updated: 2014/10/09 15:08:28 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell3.h"

int			ft_exit(t_shell **shell)
{
	free_shell(shell);
	exit (0);
}
