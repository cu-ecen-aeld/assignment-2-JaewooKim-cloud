# Default target to build the "writer" application
all: writer

# Specify the compiler and compiler flags
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall

# Define source and object files
SRC = writer.c
OBJ = writer.o

# Build the "writer" application
writer: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove the "writer" application and all .o files
clean:
	rm -f writer *.o

# Cross-compilation support
ifdef CROSS_COMPILE
CC = /home/jaewookim/Downloads/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/$(CROSS_COMPILE)gcc
endif