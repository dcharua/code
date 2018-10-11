#Daniel Charua - A01017419 - pi_server
#Files in .o extension
OBJECTS = pi_client.o
# The header files none for this project
DEPENDS =
# The executable program to be created
MAIN = client
# The compiler program to use
CC = gcc

#Options to use when compiling object files
CFLAGS = -Wall -pedantic -g
#Options to use for the final linking process none for this
LDFLAGS =
# Default rule
all: $(MAIN)

# Rule to make the executable
$(MAIN): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

# Rule to make the object files
%.o: %.c $(DEPENDS)
	$(CC) $< -c -o $@ $(CFLAGS)


#Daniel Charua - ImageRead MakeFile
#Files in .o extension
OBJECTS = pi_server.o
# The header files
DEPENDS =
# The executable program to be created
MAIN = server
# The compiler program to use
CC = gcc

#Options to use when compiling object files
CFLAGS = -Wall -pedantic -g
#Options to use for the final linking process 
LDFLAGS =

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
