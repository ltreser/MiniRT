# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 15:07:05 by mokutucu          #+#    #+#              #
#    Updated: 2024/12/05 22:10:58 by afoth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = miniRT

LIBDIR  = libs/libft/libft.a
OBJDIR  = obj
CC      = cc

CFLAGS  = -Wall #-Wextra -Werror

LDFLAGS = -lXext -lX11 -lm

RM      = rm -rf

SRC_DIR = src
SRCS    = src/main.c src/mlx_init.c src/input.c src/parse.c src/vector_calc.c src/parse_utils.c \
          src/exit.c src/screen_calculations.c

OBJS    = $(patsubst $(SRC_DIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all:    $(NAME)

$(NAME): $(OBJS) $(LIBDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBDIR) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(LIBDIR):
	@make -s -C libs/libft/

clean:
	@rm -rf $(OBJDIR)
	@make clean -C libs/libft/

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libs/libft/

re: fclean all

.PHONY: all clean fclean re
