/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:25:29 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/12/05 09:18:10 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	read_p(t_env *e, char *line, int fd)
{
	int		i;

	i = 0;
	e->temp = ft_strsplit(line, ' ');
	e->height_p = ft_atoi(e->temp[1]);
	e->width_p = ft_atoi(e->temp[2]);
	myfree(e->temp, 3);
	free(line);
	e->piece = (char **)malloc(sizeof(char *) * e->height_p);
	while (i < e->height_p)
	{
		get_next_line(fd, &line);
		e->piece[i] = line;
		i++;
	}
}

static void	init_map(t_env *e, int fd)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(fd, &line);
	e->temp = ft_strsplit(line, ' ');
	e->map_y = ft_atoi(e->temp[1]);
	e->map_x = ft_atoi(e->temp[2]);
	myfree(e->temp, 3);
	free(line);
	get_next_line(fd, &line);
	e->map = (char **)malloc(sizeof(char *) * e->map_y);
	free(line);
	while (i < e->map_y)
	{
		e->map[i] = (char *)malloc(sizeof(char) * (e->map_x + 1));
		get_next_line(fd, &line);
		ft_memcpy(e->map[i], line + 4, e->map_x + 1);
		i++;
	}
	get_next_line(fd, &line);
	read_p(e, line, fd);
}

void		start(t_env *e, int flag, int fd)
{
	init_map(e, fd);
	e->exit = 1;
	if (flag == 0)
	{
		positions(e);
		flag = 1;
	}
	if (e->up_or_down == 0)
	{
		if (place_top_left(e) == 0)
			return ;
	}
	else if (e->up_or_down == 1)
	{
		if (place_btm_right(e) == 0)
			return ;
	}
	e->exit = 0;
	ft_putstr("0 0\n");
}
