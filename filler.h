/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:26:32 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/12/04 11:26:34 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct	s_env
{
	char		**map;
	int			map_x;
	int			map_y;
	char		plyr;
	char		opp;
	int			plyr_pos_x;
	int			plyr_pos_y;
	int			opp_pos_x;
	int			opp_pos_y;
	int			up_or_down;
	char		**temp;
	char		*newline;
	char		**piece;
	int			height_p;
	int			width_p;
	int			exit;
}				t_env;

void			save_player(t_env *e, int fd);
void			positions(t_env *e);
void			start(t_env *e, int flag, int fd);
int				valid_move(t_env *e, int x, int y);
void			create_temp(t_env *e);
void			myfree(char **obj, int max);
int				place_top_left(t_env *e);
int				place_btm_right(t_env *e);

#endif
