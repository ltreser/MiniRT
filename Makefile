
NAME = miniRT

SRC = main.c mlx_init.c input.c parse.c vector_calc.c parse_utils.c \
      exit.c screen_calculations.c init.c render.c init_obj.c setup_viewport.c \
	  vector_calc_no_malloc.c point_calc.c point_calc_no_malloc.c frustum_culling.c \
	  cylinder_calc.c lighting.c calc_normal.c parse_obj.c\
	  plane_equations.c sphere_calc.c debug.c color.c cylinder.c\
	  vector_calcb.c vector_calc_no_mallocb.c cylinderb.c render_utils.c \

#cylinder_calc.c frustum_culling.c frustum_check.c
SRC_DIR = src/
OBJDIR = obj
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

INC_DIR = include/
HEADERS = $(addprefix $(INC_DIR), miniRT.h)

CC = gcc
CFLAGS = -Wall -g3 -I$(INC_DIR) -I/usr/include -Ilibs/minilibx-linux
LDFLAGS = -L libs/libft -L libs/minilibx-linux
LDLIBS = -lft -lmlx
LFLAGS = -lbsd -lXext -lX11 -lm
RM = rm -rf

LIBFT = libs/libft/libft.a
LIBMLX = libs/minilibx-linux/libmlx_Linux.a

all: $(NAME)

$(LIBFT):
	@echo "Building libft..."
	make -C libs/libft

$(LIBMLX):
	@echo "Building minilibx..."
	mkdir -p libs
	git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx-linux || true
	make -C libs/minilibx-linux

$(OBJDIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LFLAGS)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	make -C libs/libft fclean || true
	$(RM) libs/minilibx-linux
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
