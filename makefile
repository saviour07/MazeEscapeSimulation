# The following commands can be used with this Makefile:
# make all
# make compile
# make link
# make clean
# make release
# make debug

# The binary output name
BINARY = MazeEscapeSimulation

# The project directories
BINDIR := bin
SRCDIR := src
OBJDIR := obj

# The source files
# Gets all cpp files under the src directory
SRC := $(wildcard $(SRCDIR)/*.cpp)

# The object files
# Gets all the cpp file names under the src directory
# and creates a list of those file names under the
# object directory with the .o extension
# e.g. src/file.cpp -> obj/file.o
OBJ := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# The compiler flags
CXXFLAGS := -std=c++11 -pedantic-errors -Wall -Wextra -Werror

# Build everything
all: clean compile link

# Compile source files into object files
compile:
	g++ $(CXXFLAGS) -o $(OBJ) -c $(SRC)

# Link object files into binary
link:
	g++ -o $(BINDIR)/$(BINARY) $(OBJ)

# Remove all object files and delete the output binary
clean:
	rm -rf $(OBJDIR)/*
	rm -rf $(BINDIR)/*

# Add debug flag and build all
debug: CXXFLAGS += -DDEBUG -g
debug: all

# Add releas flag and build all
release: CXXFLAGS += -O2
release: all