# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 05:57:35 by ltreser           #+#    #+#              #
#    Updated: 2024/12/13 15:41:27 by afoth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRC = main.c mlx_init.c input.c parse.c vector_calc.c parse_utils.c \
      exit.c screen_calculations.c init.c
SRC_DIR = src/
OBJDIR = obj
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

INC_DIR = include/
HEADERS = $(addprefix $(INC_DIR), miniRT.h)

CC = gcc
CFLAGS = -Wall -g -I$(INC_DIR) -I/usr/include -Ilibs/minilibx-linux
LDFLAGS = -L libs/libft -L libs/minilibx-linux
LDLIBS = -lft -lmlx
LFLAGS = -lbsd -lXext -lX11 -lm
RM = rm -rf

LIBFT = libs/libft/libft.a
LIBMLX = libs/minilibx-linux/libmlx_Linux.a

all: $(NAME)

$(LIBFT):
	make -C libs/libft

$(LIBMLX):
	@mkdir -p libs
	git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx-linux || true
	make -C libs/minilibx-linux

$(OBJDIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LFLAGS)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	make -C libs/libft fclean || true
	$(RM) libs/minilibx-linux
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
