# compiler
CXX := g++
CXXFLAGS := -Wall -std=c++20 -O2

#libraries
LDFLAGS := -lncurses

# SRC and OBJ
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)

# Executable name
TARGET := game

# Default target
all: $(TARGET)


# Build executable : $^ are objects, $@ default output name (gam)
$(TARGET): $(OBJ) # Relink to newer exectuables if needed
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) 
	

# Compile source files to object files
%.o: %.cpp # Recompile .cpp if .o missing or older than the .cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Optional: convenience
.PHONY: all clean