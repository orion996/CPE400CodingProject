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
#include <list>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> intPair;

class Graph 
{
    private:
        int numVert;
        list< pair<int, int> > *vertices;
    
    public:
        Graph();
        Graph(int);
        ~Graph();
        
        void addEdge(int, int, int);
        void findShortestPath(int, int);
    
};

#endif /* GRAPH_H */

