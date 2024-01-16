# Makefile for a project with /bin, /build, /src, /includes, and /test directories

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++17 -Wall
# Output directory
BIN_DIR = bin
BUILD_DIR = build
# Source directory
SRC_DIR = src
# Include directory
INCLUDE_DIR = includes
# Test directory
TEST_DIR = test

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

# Main executable
MAIN_EXECUTABLE = $(BIN_DIR)/main

# Dependencies
DEPENDENCIES = -I$(INCLUDE_DIR)

# Targets
all: $(MAIN_EXECUTABLE)

$(MAIN_EXECUTABLE): $(OBJ_FILES) $(TEST_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(DEPENDENCIES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(DEPENDENCIES)

test: $(MAIN_EXECUTABLE)
	./$(MAIN_EXECUTABLE)

clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR)

run:
	./$(BIN_DIR)/main
doc:
	cd docs && doxygen

.PHONY: all test clean
