# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadraja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 15:18:20 by abadraja          #+#    #+#              #
#    Updated: 2016/11/21 16:36:33 by abadraja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c ft_parse.c ft_tools.c ft_transform.c ft_draw.c ft_error.c
FLAGS = -Wall -Wextra -Werror
OFILES = $(SRC:%.c=%.o)
LIB = libft/libft.a

all: $(LIB) $(NAME)

$(NAME): libft/libft.a $(OFILES)
	@gcc $(FLAGS) -o $@ $^ -Llibft -lft

$(LIB):
	@make -C libft

%.o: %.c ft_hf.h
	@gcc $(FLAGS) -Ilibft -Ift_hf.h -c -o $@ $<

clean:
	@rm -f $(OFILES)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean
