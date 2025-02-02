GREEN = \033[32m
BLUE = \033[34m
PURPLE = \033[35m
CYAN = \033[36m
RESET = \033[0m
BOLD = \033[1m

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98

TARGET = zombie

SOURCES = Zombie.cpp zombieHorde.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)
	@echo "$(GREEN)✨ Compiled with success!$(RESET)"

$(TARGET): main.cpp $(OBJECTS)
	@echo "$(PURPLE)🔨 Building the exec...$(RESET)"
	@$(CXX) $(CXXFLAGS) $^ -o $(TARGET)

%.o: %.cpp
	@echo "$(CYAN)📝 Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)🧹 Cleaning object files...$(RESET)"
	@rm -f $(OBJECTS) $(TARGET)
	@echo "$(GREEN)✨ Object files clean!$(RESET)"

fclean: clean
	@echo "$(BLUE)🧹 Cleaning exec files...$(RESET)"
	@rm -f $(TARGET)
	@echo "$(GREEN)✨ Exec files clean!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
