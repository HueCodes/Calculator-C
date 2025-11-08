# Compiler settings
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -O2
TARGET = calculator
SRC = calculator.c

# Default target
all: $(TARGET)

# Build the calculator
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean build artifacts
clean:
	rm -f $(TARGET) *.o

# Run the calculator
run: $(TARGET)
	./$(TARGET)

# Rebuild from scratch
rebuild: clean all

.PHONY: all clean run rebuild
