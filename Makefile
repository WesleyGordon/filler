# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 11:24:30 by wvon-gra          #+#    #+#              #
#    Updated: 2017/12/04 12:09:37 by wvon-gra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= filler

CFLAGS	= -Wall -Werror -Wextra

SRC =	main.c \
		start.c \
		save_player.c \
		positions.c \
		valid_move.c \
		myfree.c \
		place_move.c \

OBJ = $(SRC:.c=.o)

LIBFLAGS = -I./ -L ./libft -lft

all: $(NAME)

$(NAME):
		make all -C libft/ 
			gcc $(CFLAGS) -o $(NAME) $(SRC) $(LIBFLAGS)
		@echo "-----Compiled-----"
clean:
		rm -f $(OBJ)
			make clean -C libft/

fclean: clean
		rm -f $(NAME)
			make fclean -C libft/

re: fclean all
