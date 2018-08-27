#Daniel Charua - Generic makefile
#Files in .o extension
OBJECTS = simpleTest.o stringTools.o
# The header files
DEPENDS = stringTools.h
# The executable program to be created
MAIN = simpleTest
# The compiler program to use
CC = gcc

#Options to use when compiling object files
CFLAGS = -Wall -pedantic -g
#Options to use for the final linking process (this is math library)
LDFLAGS = -lm

# Default rule
all: $(MAIN)

# Rule to make the executable
$(MAIN): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

# Rule to make the object files
%.o: %.c $(DEPENDS)
	$(CC) $< -c -o $@ $(CFLAGS)

# Clear the compiled files
clean:
	rm -rf $(MAIN) *.o

# run de program
run:
	./$(MAIN)

# Make a zip file
zip:
	zip $(MAIN).zip *

# Indicate the rules that do not refer to a file
.PHONY: clean run zip
