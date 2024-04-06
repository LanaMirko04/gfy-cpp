# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -Wall -Wextra -std=c++17 -I./include -I./lib/argspp/src

# Directories
OBJ_DIR := obj
BIN_DIR := bin

# Main project source directory
SRC_DIR := src

# Main project source files
MAIN_SRC := $(wildcard $(SRC_DIR)/*.cpp)

# Object files
MAIN_OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(MAIN_SRC))

# Executable name
EXECUTABLE := $(BIN_DIR)/gfy-cpp

# Targets
all: directories $(EXECUTABLE)

$(EXECUTABLE): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean submodules

clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@for dir in $(SUBMODULE_DIRS); do \
		$(MAKE) -C $$dir clean; \
	done
