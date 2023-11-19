# Compiler and flags
CC=gcc
CFLAGS=-Wall

# Source files
SRC_DIR=.
BIN_DIR=./bin

# Programs
CHAT=$(SRC_DIR)/chat.c

# Default target
all: directories chat

# Create the bin directory
directories:
	@mkdir -p $(BIN_DIR)

chat: $(CHAT)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/chat $(CHAT)

# Clean up
clean:
	rm -rf $(BIN_DIR)
