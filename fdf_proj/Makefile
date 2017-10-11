# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadraja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 15:18:20 by abadraja          #+#    #+#              #
#    Updated: 2017/01/10 10:13:39 by abadraja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = main.c draw.c eco.c gvncode2.c gvncode3.c key_hook.c lines.c prepare.c
FLAGS = -lmlx -framework OpenGl -framework AppKit -lft -Llibft
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
