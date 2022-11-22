NAME = fdf

CC = gcc
CFLAGES = -Wall -Werror -Wextra
VALGRIND = -g
CHECK = -fsanitize=address
MATH_LIB = -lm

LIBFT_DIR = ./libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
LIBFT_INC = $(LIBFT_DIR)

OS = $(shell uname)
ifeq ($(OS), Linux)
	MLX_DIR = ./minilibx-linux/
	MLX = $(MATH_LIB) -lXext -lX11
else
	MLX_DIR = ./minilibx_macos/
	MLX = $(MATH_LIB) -framework OpenGL -framework AppKit
endif

MLX_LIB = $(MLX_DIR)libmlx.a
MLX_INC = $(MLX_DIR)

INC_DIR = ./inc/
INCS = fdf.h
INCLUDES = $(addprefix $(INC_DIR), $(INCS))

SRC_DIR = ./src/
SRCS = fdf.c \
	t_fdf_memory.c \
	read_map_row_col.c \
	read_map_matrix.c \
	draw.c \
	bresenham.c \
	zoom.c \
	projection.c \
	shift.c \
	color.c \
	key_event.c \
	key_event_sub.c \
	control.c \
	mlx_utils.c \
	utils.c \
	map_print.c

SOURCES = $(addprefix $(SRC_DIR), $(SRCS))

OBJ_DIR = ./obj/
OBJS = $(SRCS:.c=.o)
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJS))

LIBRARY = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLX)
HEADERS = -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX_INC)

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
NC = \033[1;0m

ifdef WITH_LEAK
	COMPILE = @$(CC) -o $(NAME) $(OBJECTS) $(CFLAGES) $(LIBRARY) $(HEADERS) $(VALGRIND)
else
	ifdef WITH_CHECK
		COMPILE = @$(CC) -o $(NAME) $(OBJECTS) $(CFLAGES) $(LIBRARY) $(HEADERS) $(CHECK)
	else
		COMPILE = @$(CC) -o $(NAME) $(OBJECTS) $(CFLAGES) $(LIBRARY) $(HEADERS)
	endif
endif

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJECTS) $(LIBFT_LIB) $(MLX_LIB)
	$(COMPILE)
	@echo "$(GREEN)[ Created excutable file(fdf) ... ]$(NC)"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)[ Created obj directory ... ]$(NC)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@echo "$(GREEN)[ Compiling... $? -> $@ ]$(NC)"
	@$(CC) $(CFLAGES) $(HEADERS) -c $? -o $@

$(LIBFT_LIB) :
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(YELLOW)[ Created libft.a ... ]$(NC)"

$(MLX_LIB) :
	@$(MAKE) -sC $(MLX_DIR)
	@echo "$(YELLOW)[ Created libmlx.a ... ]$(NC)"

clean :
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@$(MAKE) clean -sC $(MLX_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[ libft, mlx, fdf cleaned ... ]$(NC)"

fclean : clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@rm -rf $(NAME)
	@echo "$(RED)[ libft, fdf fcleaned ... ]$(NC)"

re :
	@$(MAKE) -s fclean
	@$(MAKE) -s all

leak :
	make WITH_LEAK=1 all
	valgrind --leak-check=full --show-leak-kinds=all ./fdf test_maps/42.fdf

check :
	make WITH_CHEKC=1 all

42 :
	./fdf test_maps/42.fdf

norm :
	norminette src/* inc/*

.PHONY : all clean fclean re leak check 42 norm
