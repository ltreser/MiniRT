# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 02:24:33 by ltreser           #+#    #+#              #
#    Updated: 2025/04/22 16:02:19 by ltreser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

LIBFT_SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strlcat.c ft_strlcpy.c  ft_strjoin.c\
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c  ft_atol.c  \
	ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstlast.c \
	ft_contains_c.c ft_isupper.c ft_islower.c ft_capitalize.c ft_count_words.c \
	ft_chop.c ft_atof.c

LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)

PRINTF_SRCS	= ft_printf.c ft_puthexanbr_len.c ft_putstr_len.c ft_putchar_len.c ft_putnbr_len.c ft_putunsnbr_len.c

PRINTF_OBJS	= $(PRINTF_SRCS:.c=.o)

GNL_SRCS	= get_next_line.c get_next_line_utils.c

GNL_OBJS	= $(GNL_SRCS:.c=.o)

GC_SRCS	= ft_gc_malloc.c ft_gc_malloc2.c

GC_OBJS	= $(GC_SRCS:.c=.o)

CC			= gcc

LIBFT_PATH	= ./src/

PRINTF_PATH	= ./printf/

GNL_PATH	= ./gnl/

GC_PATH     = ./gc/

INCLUDES_PATH	= ./includes

CFLAGS		= -Wall -Werror -Wextra -g -I $(INCLUDES_PATH)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(addprefix $(LIBFT_PATH), $(LIBFT_OBJS)) $(addprefix $(PRINTF_PATH), $(PRINTF_OBJS)) $(addprefix $(GNL_PATH), $(GNL_OBJS)) $(addprefix $(GC_PATH), $(GC_OBJS))
	ar rc $(NAME) $(addprefix $(LIBFT_PATH), $(LIBFT_OBJS)) $(addprefix $(PRINTF_PATH), $(PRINTF_OBJS)) $(addprefix $(GNL_PATH), $(GNL_OBJS))  $(addprefix $(GC_PATH), $(GC_OBJS))

clean:
	rm -f $(addprefix $(LIBFT_PATH), $(LIBFT_OBJS)) $(addprefix $(PRINTF_PATH), $(PRINTF_OBJS)) $(addprefix $(GNL_PATH), $(GNL_OBJS)) $(addprefix $(GC_PATH), $(GC_OBJS))

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
