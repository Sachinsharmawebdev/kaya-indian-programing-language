# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -g
LDFLAGS =

# Directories
SRC_DIR = src
BIN_DIR = bin
LIB_DIR = lib
TEST_DIR = test
OBJ_DIR = obj

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Executable output
EXEC = $(BIN_DIR)/kaya_test

# Create the obj directory and its subdirectories
$(shell mkdir -p $(OBJ_DIR)/$(basename $(notdir $(SRC_DIR)))/)

# Target: Default build
all: $(EXEC)

# Target: Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(dir $@)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

# Target: Link object files into the executable
$(EXEC): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ_FILES) $(LDFLAGS) -o $(EXEC)

# Target: Clean up compiled files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Target: Run the tests
run:
	$(EXEC)

.PHONY: all clean run
