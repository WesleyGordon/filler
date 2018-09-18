/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:25:16 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/12/05 09:17:55 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		place_top_left(t_env *e)
{
	int x;
	int y;

	y = 1 - e->height_p;
	while (y < e->map_y)
	{
		x = 1 - e->width_p;
		while (x < e->map_x)
		{
			if (valid_move(e, x, y) == 1)
			{
				ft_putnbr(y);
				ft_putchar(' ');
				ft_putnbr(x);
				ft_putchar('\n');
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int		place_btm_right(t_env *e)
{
	int col;
	int row;

	row = e->map_y + e->height_p - 1;
	while (row > 1 - e->height_p)
	{
		col = e->map_x + e->width_p - 1;
		while (col > 1 - e->width_p)
		{
			if (valid_move(e, col, row) == 1)
			{
				ft_putnbr(row);
				ft_putchar(' ');
				ft_putnbr(col);
				ft_putchar('\n');
				return (0);
			}
			col--;
		}
		row--;
	}
	return (1);
}
