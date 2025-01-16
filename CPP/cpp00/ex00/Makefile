GREEN = \033[32m
BLUE = \033[34m
PURPLE = \033[35m
CYAN = \033[36m
RESET = \033[0m
BOLD = \033[1m

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98

TARGET = megaphone
SOURCES = megaphone.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)
	@echo "$(GREEN)✨ Compiled with success!$(RESET)"

$(TARGET): $(OBJECTS)
	@echo "$(PURPLE)🔨 Building the exec...$(RESET)"
	@$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	@echo "$(CYAN)📝 Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)🧹 Cleaning tmp files...$(RESET)"
	@rm -f $(OBJECTS) $(TARGET)
	@echo "$(GREEN)✨ Dir clean!$(RESET)"

.PHONY: all clean
