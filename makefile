CXX := c++
CXXFLAGS := -g

obj := edge.o vertex.o graph.o

Program: $(obj)
	$(CXX) $(obj) main.cpp -o Program
	
edge.o: edge.cpp edge.h
	$(CXX) $(CXXFLAGS) -c edge.cpp -o edge.o
	
vertex.o: vertex.cpp vertex.h
	$(CXX) $(CXXFLAGS) -c vertex.cpp -o vertex.o
	
graph.o: graph.cpp graph.h
	$(CXX) $(CXXFLAGS) -c graph.cpp -o graph.o

	
.PHONY: clean
clean: 
	-rm  main.o $(obj)
	
	
