# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -O2

# Target executable
TARGET = exe

# Source and header files (now in src/ and include/)
SRCS = src/main.cpp src/blackScholes.cpp src/stats.cpp
HEADERS = include/blackScholes.h include/stats.h

# Default target
all: $(TARGET)

# Build executable
$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -Iinclude $(SRCS) -o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(TARGET)

.PHONY: all run clean
