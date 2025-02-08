NAME		=	sed_is_for_losers
TESTS_NAME		=	tester

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -std=c++98

# directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/
TESTS_DIR   =	tests/
TESTS_OBJ_DIR   =	obj/tests

# controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

#source files
SRC_FILES	=	main.cpp
TESTS_FILES	=	main_test.cpp

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)
TESTS_OBJ_FILES	=	$(TEST_FILES:.cpp=.o)

#paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
TESTS			=	$(addprefix $(TESTS_DIR), $(TESTS_FILES))

#all rule
all: $(NAME)
	@if command -v figlet > /dev/null 2>&1; then \
		figlet "$(NAME)" | printf "$(GREEN)%s$(RESET)\n" "$$(cat)"; \
	else \
		printf "$(GREEN)compiled$(RESET)\n"; \
	fi

# tester rule
test: $(TESTS_NAME)
	@if command -v figlet > /dev/null 2>&1; then \
		figlet "$(TESTS_NAME)" | printf "$(GREEN)%s$(RESET)\n" "$$(cat)"; \
	else \
		printf "$(GREEN)compiled$(RESET)\n"; \
	fi

#compile the executable
$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile the tester
$(TESTS_NAME): $(TESTS)
	@echo "$(YELLOW)Compiling [$(TESTS_NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) $(TESTS) -o $(TESTS_NAME)
	@echo "$(GREEN)Finished [$(TESTS_NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#compile tests objects
$(TESTS_OBJ_DIR)%.o:$(TESTS_DIR)%.cpp
	@mkdir -p $(TESTS_OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"


#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(BLUE)Deleting all objects from /ex03...$(RESET)"; else \
	echo "No objects to remove from /ex03."; \
	fi;
	@if [ -d "$(TESTS_OBJ_DIR)" ]; then \
	rm -rf $(TESTS_OBJ_DIR); \
	echo "$(BLUE)Deleting all tests objects from /ex03...$(RESET)"; else \
	echo "No tests objects to remove from /ex03."; \
	fi;


#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(BLUE)Deleting $(NAME) from /ex03...$(RESET)"; else \
	echo "No Executable to remove from /ex03."; \
	fi;
	@if [ -f "$(TESTS_NAME)" ]; then \
	rm -f $(TESTS_NAME); \
	echo "$(BLUE)Deleting $(TESTS_NAME) from /ex03...$(RESET)"; else \
	echo "No Tests Executables to remove from /ex03."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re test
