# The following commands can be used with this Makefile:
# make all
# make clean
# make distclean
# make release
# make debug
.PHONY: all clean distclean debug release

# The binary output name
binary_NAME := MazeEscapeSimulation

# The project directories
BIN_DIR := bin
SRC_DIR := src
OBJ_DIR := obj

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(OBJ_DIR)/%.o=$(SRCS))

# The compiler flags
CXXFLAGS += -std=c++11 -pedantic-errors -Wall -Wextra -Werror

# Build everything
all: clean $(BIN_DIR)/$(binary_NAME)

# Remove all object files and delete the output binary
clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(BIN_DIR)/*
distclean: clean

# Build the output binary
# Currently not outputting any object files
# $^ is the list of input files
# $@ is the output name i.e. $(BIN_DIR)/$(binary_NAME)
$(BIN_DIR)/$(binary_NAME): $(SRCS)
	@echo Input files: $^
	$(CXX) $(CXXFLAGS) -o $@ $^

# Add debug flag and build all
debug: CXXFLAGS += -DDEBUG -g
debug: all

# Add releas flag and build all
release: CXXFLAGS += -O2
release: all
