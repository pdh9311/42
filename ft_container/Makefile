NAME		= ft_container

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
# CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g
# CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address

INC_DIR		= ./inc/
SRC_DIR		= ./src/
GIVEN_DIR	= ./given/

HEADER		= -I$(INC_DIR)

# color
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
NC			= \033[1;0m

all :
	@make vector
	@make map
	@make set
	@make rbtree
	@make given
	@make clean

vector :
	@echo "$(GREEN)[vector test]$(NC)"
	@$(CXX) $(CXXFLAGS) $(SRC_DIR)ft_vector_test.cpp $(HEADER) -o $(NAME) && ./$(NAME) > a
	@$(CXX) $(CXXFLAGS) $(SRC_DIR)std_vector_test.cpp $(HEADER) -o $(NAME) && ./$(NAME) > b
	@diff a b

map :
	@echo "$(GREEN)[map test]$(NC)"
	@$(CXX) $(CXXFLAGS) $(SRC_DIR)ft_map_test.cpp $(HEADER) -o $(NAME) && ./$(NAME) > a
	@$(CXX) $(CXXFLAGS) $(SRC_DIR)std_map_test.cpp $(HEADER) -o $(NAME) && ./$(NAME) > b
	@diff a b

set :
	@echo "$(GREEN)[set test]$(NC)"
	@$(CXX) $(CXXFLAGS) $(SRC_DIR)ft_set_test.cpp $(HEADER) -o $(NAME) && ./$(NAME) > a
	@$(CXX) $(CXXFLAGS) $(SRC_DIR)std_set_test.cpp $(HEADER) -o $(NAME) && ./$(NAME) > b
	@diff a b

rbtree:
	@echo "$(GREEN)[rbtree test]$(NC)"
	@$(CXX) $(CXXFLAGS) $(SRC_DIR)rbtree_test.cpp $(HEADER) -o $(NAME) && ./$(NAME)

given :
	@echo "$(GREEN)[main test]$(NC)"
	@$(CXX) $(CXXFLAGS) $(GIVEN_DIR)main.cpp $(HEADER) -o $(NAME) && ./$(NAME) 42

clean :
	@echo "$(YELLOW)[test clean]$(NC)"
	@rm -rf $(NAME) a b

.PHONY : all clean vector map set rbtree given