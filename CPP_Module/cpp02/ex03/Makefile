NAME		= a.out

CC			= clang++
CFLAGE		= -Wall -Wextra -Werror -std=c++98

INC_DIR		= ./inc/
INCLUDES	= Fixed.hpp Point.hpp
INCS		= $(addprefix $(INC_DIR), $(INCLUDES))

SRC_DIR		= ./src/
ifdef WITH_TEST
SOURCES		= test.cpp Fixed.cpp Point.cpp bsp.cpp
else
SOURCES		= main.cpp Fixed.cpp Point.cpp bsp.cpp
endif
SRCS		= $(addprefix $(SRC_DIR), $(SOURCES))

OBJ_DIR		= ./obj/
OBJECTS		= $(SOURCES:.cpp=.o)
OBJS		= $(addprefix $(OBJ_DIR), $(OBJECTS))

HEADER		= -I$(INC_DIR)

# color
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
NC			= \033[1;0m

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	@$(CC) -o $@ $(OBJS) $(CFLAGE) $(HEADER)
	@echo "$(GREEN)[ Created excutable file ... ]$(NC)"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)[ Created obj directory ... ]$(NC)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp $(INCS)
	@echo "$(YELLOW)[ Compiling... $< -> $@ ]$(NC)"
	@$(CC) -c $< -o $@ $(CFLAGE) $(HEADER)

clean :
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[ cleaned ... ]$(NC)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED)[ fcleaned ... ]$(NC)"

re : fclean all

test :
	@$(MAKE) -s all WITH_TEST=1

.PHONY : all clean fclean re test
