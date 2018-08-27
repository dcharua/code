#Variable used for the implicit rules
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
#LDFLAGS = -lm
OBJECTS = test_postfix.o
DEPS = node.h Postfix.h PostfixTree.h Stack.h TreeNode.h

#Basic rule to compile the program
main: $(OBJECTS)
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS)

main: test_postfix.o
	$(CXX) $^ -o $@ $(CXXFLAGS)

#checks for changes in .h files
%.o: %.cpp $(DEPS)
	$(CXX) -o $@ $< $(CXXFLAGS) -c

clean:
	-rm -f test main *.o

.PHONY: clean
