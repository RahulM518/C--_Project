#makefile to run all .c,.h files
CC := gcc
CFLAGS := -g

# Directories
SRC_ := src
INC_:= include
OBJ_ := obj

# Source and object files
# Find all .c files in the source directory
SRC := $(wildcard $(SRC_)/*.c)
# Generate object file names based on source file names
OBJ := $(patsubst $(SRC_)/%.c,$(OBJ_)/%.o,$(SRC))

# Target executable
TARGET := main

# Default target: build the executable
all: $(TARGET)
#remove @ to show all commands
# Run the executable
run:
	@./$(TARGET)

# Build the executable from object files
$(TARGET): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

# Compile individual source files into object files
$(OBJ_)/%.o: $(SRC_)/%.c
	@mkdir -p $(OBJ_)
	@$(CC) $(CFLAGS) -c -o $@ $<

# Clean up generated files
clean:
	@rm -f $(OBJ_)/*.o $(TARGET)

# Declare phony targets (targets that are not files)
.PHONY: all clean run
