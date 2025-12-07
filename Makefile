# Makefile for Code Review Demo

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = demo
SRC_DIR = src
INCLUDE_DIR = include

# Source files
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/calculator.c $(SRC_DIR)/string_utils.c
OBJECTS = $(SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets
.PHONY: all clean
