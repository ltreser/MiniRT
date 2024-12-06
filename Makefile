# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 05:57:35 by ltreser           #+#    #+#              #
#    Updated: 2024/12/06 20:45:56 by afoth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRC = main.c mlx_init.c input.c parse.c vector_calc.c parse_utils.c \
      exit.c screen_calculations.c init.c

SRC_DIR = src/

OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

INC_DIR = include/

HEADERS = $(addprefix $(INC_DIR), miniRT.h)

CC = gcc

CFLAGS = -Wall -g -Iinclude/ -I/usr/include -Iminilibx-linux #-O3 TODO put in flags later

LDLIBS = -lft -lmlx

LDFLAGS = -L libft -L minilibx-linux

LFLAGS = -lbsd -lXext -lX11 -lm

RM = rm -rf

LIBFT = libft/libft.a

LIBMLX = minilibx-linux/libmlx_Linux.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I/usr/include -Imlx_linux -O3 -c  $< -o $@

$(LIBFT):
	make -C ./libft

$(LIBMLX):
	git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux
	make -C minilibx-linux

$(NAME): $(HEADERS) $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	make -C libft fclean
	$(RM) minilibx-linux
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
