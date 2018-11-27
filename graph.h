/**
*@author Nick Jordy
*@brief Definition of a Graph
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> intPair;

class Graph 
{
    private:
        int numVert;
        vector< pair<int, int> > *vertices;
    
    public:
        Graph();
        Graph(int);
        ~Graph();
        
        void addEdge(int, int, int);
        void findShortestPath(int);
    
};

#endif /* GRAPH_H */

