/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:26:19 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/12/05 09:18:03 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_map(t_env *e, int x, int y)
{
	if (x < 0 || y < 0 || x >= (e->map_x) || y >= (e->map_y))
		return (0);
	if (e->map[y][x] == e->plyr || e->map[y][x] == e->plyr + 32)
		return (1);
	if (e->map[y][x] == e->opp || e->map[y][x] == e->opp + 32)
	{
		return (-1);
	}
	return (2);
}

int			valid_move(t_env *e, int x, int y)
{
	int		col;
	int		row;
	int		valid;

	row = 0;
	valid = 0;
	while (row < e->height_p)
	{
		col = 0;
		while (col < e->width_p)
		{
			if (e->piece[row][col] == '*')
			{
				if (check_map(e, x + col, y + row) == 0 || valid > 1)
					return (0);
				else if (check_map(e, x + col, y + row) == -1)
					return (-1);
				else if (check_map(e, x + col, y + row) == 1)
					valid++;
			}
			col++;
		}
		row++;
	}
	return (valid == 1);
}
