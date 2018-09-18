/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:26:55 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/12/05 09:18:15 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_player(t_env *e, int fd)
{
	char *line;

	line = "\0";
	get_next_line(fd, &line);
	if (ft_atoi(line + 10) == 1)
	{
		e->plyr = 'O';
		e->opp = 'X';
	}
	else
	{
		e->plyr = 'X';
		e->opp = 'O';
	}
}
