# The following commands can be used with this Makefile:
# make all
# make build
# make clean
# make distclean
# make release
# make debug
.PHONY: all build clean distclean debug release

# The binary output name
binary_NAME := MazeEscapeSimulation

# The project directories
BIN_DIR := bin
SRC_DIR := src
OBJ_DIR := obj

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# The compiler flags
CXXFLAGS += -std=c++11 -pedantic-errors -Wall -Wextra -Werror

# Build everything
all: clean build

# Build main executable
build: clean $(BIN_DIR)/$(binary_NAME)

# Remove all object files and delete the output binary
clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(BIN_DIR)/*
distclean: clean

# Build the output binary
# $^ is the list of input files
# $@ is the output name i.e. $(BIN_DIR)/$(binary_NAME)
$(BIN_DIR)/$(binary_NAME): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Override the built-in compile rule to
# This will output the object files to the obj dir
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Add debug flag and build all
debug: CXXFLAGS += -DDEBUG -g
debug: all

# Add releas flag and build all
release: CXXFLAGS += -O2
release: all
