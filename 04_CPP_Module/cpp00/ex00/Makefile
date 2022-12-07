NAME     = megaphone

CC       = clang++
CFLAGE   = -Wall -Wextra -Werror -std=c++98

SOURCES  = megaphone.cpp
OBJECTS  = $(SOURCES:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	@$(CC) -o $@ $(OBJECTS) $(CFLAGE)

%.o : %.cpp
	$(CC) -c $< -o $@ $(CFLAGE)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
