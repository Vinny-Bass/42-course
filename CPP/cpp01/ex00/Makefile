GREEN = \033[32m
BLUE = \033[34m
PURPLE = \033[35m
CYAN = \033[36m
RESET = \033[0m
BOLD = \033[1m

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98

TARGET = zombie
TEST_TARGET = test_zombie

SOURCES = $(filter-out main.cpp, $(wildcard *.cpp))
TEST_SOURCES = $(wildcard tests/*.cpp) $(SOURCES)

OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:%.cpp=%.o)

all: $(TARGET)
	@echo "$(GREEN)✨ Compiled with success!$(RESET)"

$(TARGET): main.cpp $(OBJECTS)
	@echo "$(PURPLE)🔨 Building the exec...$(RESET)"
	@$(CXX) $(CXXFLAGS) $^ -o $(TARGET)

%.o: %.cpp
	@echo "$(CYAN)📝 Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	@echo "$(PURPLE)🔨 Running tests...$(RESET)"
	@./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS)
	@echo "$(PURPLE)🔨 Building tests...$(RESET)"
	@$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	@echo "$(BLUE)🧹 Cleaning object files...$(RESET)"
	@rm -f $(OBJECTS) $(TARGET)
	@echo "$(GREEN)✨ Object files clean!$(RESET)"

fclean: clean
	@echo "$(BLUE)🧹 Cleaning exec files...$(RESET)"
	@rm -f $(TARGET) $(TEST_TARGET)
	@rm -f tests/*.o
	@echo "$(GREEN)✨ Exec files clean!$(RESET)"

re: fclean all

.PHONY: all clean fclean re test
