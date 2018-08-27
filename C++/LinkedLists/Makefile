#Variable used for the implicit rules
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
#LDFLAGS = -lm
OBJECTS = testVectors.o Vector3D.o
DEPS = node.h linkedList.h Vector3D.h

#Basic rule to compile the program
vectors: $(OBJECTS)
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS)
	#testVectors.o Vector3D.o -o vectors $(CXXFLAGS) $(LDFLAGS)
	#Basic rule to compile the program
test: test.o
	$(CXX) $^ -o $@ $(CXXFLAGS)

#checks for changes in .h files
%.o: %.cpp $(DEPS)
	$(CXX) -o $@ $< $(CXXFLAGS) -c

clean:
	-rm -f test vectors *.o

.PHONY: clean
