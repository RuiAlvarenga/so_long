# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 17:43:10 by remanuel          #+#    #+#              #
#    Updated: 2023/05/11 20:21:32 by remanuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./minilibx_linux -lmlx -I ./minilibx_linux -lXext -lX11 -lm
RM = rm -f

SRC = ./src/so_long.c
SRC_PATH = ./src/
O_SRC = $(SRC_R:.c=.o)

all: $(NAME)

$(NAME): $(O_SRC)
	$(CC) $(CFLAGS) -lm $(SRC) $(MLXFLAGS) -o $(NAME)
	echo "\033[1;32mCompiled:\033[0;97m so_long \033[0;97m"

clean: 
	$(RM) $(O_SRC)
	echo "\033[1;31mDestroyed:\033[1;31m\033[0;97m All objects \033[0;97m"

fclean: clean
		$(RM) $(NAME)
		echo "\033[1;31mDestroyed:\033[1;31m\033[0;97m so_long \033[0;97m"

re: 	fclean all

#isto faz com que não apareça escrito os ficheiros com make e lalala

.PHONY: all clean fclean re
