NAME = philo

CC = gcc
CFLAGES = -Wall -Werror -Wextra
THREAD = -pthread

INC_DIR = ./inc/
INCS = philo.h
INCLUDES = $(addprefix $(INC_DIR), $(INCS))

SRC_DIR = ./src/
SRCS = main.c \
	init.c \
	thread.c \
	routine.c \
	print.c \
	utils.c

SOURCES = $(addprefix $(SRC_DIR), $(SRCS))

OBJ_DIR = ./obj/
OBJS = $(SRCS:.c=.o)
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJS))

HEADERS = -I$(INC_DIR)

OS = $(shell uname)
ifeq ($(OS), Linux)
GREP_OPT = -P
CORE_CNT = grep ^processor /proc/cpuinfo | wc -l
THREAD_CNT = grep -c processor /proc/cpuinfo
else
GREP_OPT = -E
CORE_CNT = sysctl hw.physicalcpu
THREAD_CNT = sysctl hw.logicalcpu
endif

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
NC = \033[1;0m

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJECTS)
	@$(CC) -o $(NAME) $(OBJECTS) $(CFLAGES) $(THREAD) $(HEADERS)
	@echo "$(GREEN)[ Created excutable file ... ]$(NC)"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)[ Created obj directory ... ]$(NC)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@echo "$(YELLOW)[ Compiling... $? -> $@ ]$(NC)"
	@$(CC) $(CFLAGES) $(HEADERS) -c $? -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[cleaned ... ]$(NC)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED)[fcleaned ... ]$(NC)"
	@rm -rf ./a.out

re :
	@$(MAKE) -s fclean
	@$(MAKE) -s all


norm :
	norminette src/* inc/*

core_thread :
	@echo "$(GREEN)core count$(NC)"
	@$(CORE_CNT)
	@echo "$(GREEN)thread count$(NC)"
	@$(THREAD_CNT)
	
test :
	./philo 4 410 200 200

testfile :
	@$(MAKE) -s re
	gcc test.c && ./a.out

grep :
	@echo "$(BLUE)grep $(GREP_OPT) \"1 is eating\" file | wc -l$(NC)"
	@grep $(GREP_OPT) "\t1.*is eating" file | wc -l

	@echo "$(BLUE)grep $(GREP_OPT) \"2 is eating\" file | wc -l$(NC)"
	@grep $(GREP_OPT) "\t2.*is eating" file | wc -l

	@echo "$(BLUE)grep $(GREP_OPT) \"3 is eating\" file | wc -l$(NC)"
	@grep $(GREP_OPT) "\t3.*is eating" file | wc -l

	@echo "$(BLUE)grep $(GREP_OPT) \"4 is eating\" file | wc -l$(NC)"
	@grep $(GREP_OPT) "\t4.*is eating" file | wc -l

	@echo "$(BLUE)grep $(GREP_OPT) \"5 is eating\" file | wc -l$(NC)"
	@grep $(GREP_OPT) "\t5.*is eating" file | wc -l

.PHONY : all clean fclean re norm core_thread test grep
