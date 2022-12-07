NAME		= a.out

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

INC_DIR		= ./inc/
INCLUDES	= Color.hpp Bureaucrat.hpp Form.hpp \
			  ShrubberyCreationForm.hpp \
			  RobotomyRequestForm.hpp \
			  PresidentialPardonForm.hpp \
			  Intern.hpp
INCS		= $(addprefix $(INC_DIR), $(INCLUDES))

SRC_DIR		= ./src/
ifdef WITH_TEST
SOURCES		= test.cpp
else
SOURCES		= main.cpp Bureaucrat.cpp Form.cpp \
			  ShrubberyCreationForm.cpp \
			  RobotomyRequestForm.cpp \
			  PresidentialPardonForm.cpp \
			  Intern.cpp
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
	@$(CXX) -o $@ $(OBJS) $(CXXFLAGS) $(HEADER)
	@echo "$(GREEN)[ Created excutable file ... ]$(NC)"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)[ Created obj directory ... ]$(NC)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp $(INCS)
	@echo "$(YELLOW)[ Compiling... $< -> $@ ]$(NC)"
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(HEADER)

clean :
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[ cleaned ... ]$(NC)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED)[ fcleaned ... ]$(NC)"
	@rm -rf *_shrubbery

re : fclean all

test :
	@$(MAKE) -s all WITH_TEST=1

.PHONY : all clean fclean re test
