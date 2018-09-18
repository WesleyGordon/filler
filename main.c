/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:25:45 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/12/05 09:18:29 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_env	e;
	int		fd;
	int		flag;

	flag = 0;
	e.exit = 1;
	fd = 0;
	save_player(&e, fd);
	while (1)
	{
		start(&e, flag, fd);
		myfree(e.map, e.map_y);
		myfree(e.piece, e.height_p);
		if (e.exit == 0)
			return (0);
	}
}
