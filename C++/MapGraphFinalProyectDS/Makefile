# Makefile to compile a program using SFML
# For more information on makefiles, read:
#   http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

# Variables with the options for compilation
CXX = g++
CXXFLAGS = -std=c++11 -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# List of the objects to compile
OBJECTS = main.o
DEPENDS = Graph.hpp LinkedList.h InfoNode.hpp Queue.hpp Stack.hpp Vertex.hpp Edge.hpp VisualGraph.hpp
# Variables with rule names
MAIN = main

# Default rule
all: $(MAIN)

# Rule to compile object files
# Commented because it is the same as an explicit rule in Make
#   https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_10.html
#%.o: %.c
	#$(CXX) -c -o $@ $< $(CXXFLAGS)

# Check for changes in the DEPENDS files
%.o: %.cpp $(DEPENDS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

# Rule to compile the program
$(MAIN): $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

clean:
	-rm -f *.o $(MAIN)

.PHONY: all clean
