# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: tests

# Build targets
tests: tests.c remove.c remove.h list.o
	$(CC) $(CFLAGS) -o tests tests.c remove.c list.o

# Run target
run: tests
	./tests

# Clean target
clean:
	rm -f tests
