#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <cstdlib>

#define SIZE 100

using namespace std;

class Graph 
{
    private:
        int numVert;
        int graph[SIZE][SIZE];
        bool* visited;
    
    public:
        Graph();
        Graph(int);
        ~Graph();
        
        void addEdge(int, int, int);
        void print();
        
    
};

#endif /* GRAPH_H */

