CXX := c++
CXXFLAGS := -g

obj :=  graph.o

Program: $(obj)
	$(CXX) $(obj) main.cpp -o Program
	
graph.o: graph.cpp graph.h
	$(CXX) $(CXXFLAGS) -c graph.cpp -o graph.o

	
.PHONY: clean
clean: 
	-rm $(obj) Program
	
	
