# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadraja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 15:18:20 by abadraja          #+#    #+#              #
#    Updated: 2017/06/29 17:19:54 by abadraja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
SRCS = srcs/*.c srcs/math_part/*.c
LIBS = -Llibft -lft -lmlx -framework OpenGL -framework AppKit -lm
CC = gcc
FLAGS = -Wall -Werror -Wextra -Ofast

all: $(NAME)

$(NAME):
		make -C libft
			$(CC)  $(SRCS) $(LIBS) -o $(NAME)

clean:
		make -C libft clean

fclean:
		make -C libft fclean
			rm -rf $(NAME)
fast:
	$(CC)  $(SRCS) $(LIBS) -o $(NAME)

re: fclean all

.PHONY: all clean
