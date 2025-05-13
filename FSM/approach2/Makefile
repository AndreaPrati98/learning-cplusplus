# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

# Paths and names
TARGET := my_program.out

# sources to build from
SRCS := main.cpp Light.cpp
# folder to hold compiled files still to be linked
BUILD_DIR := build

# Take everything in SRCS, and for each filename, replace the .cpp extension with .o
#OBJS = $(SRCS:.cpp=.o)

OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Link step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Make sure build directory exists
# The | $(BUILD_DIR) means $(BUILD_DIR) is an order-only prerequisite, 
# i.e., it must exist, but doesn’t trigger recompilation just because it changed.
$(BUILD_DIR):
	@echo "Creating folder: $(shell pwd)/$(BUILD_DIR)";mkdir -p $(BUILD_DIR)

# Compile .cpp to .o in build dir
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	@echo "Cleaning";find . -name "*.out" -delete -o -name "*.o" -delete

