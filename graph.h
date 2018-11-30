/**
*@author Nick Jordy
*@brief Graph Declaration
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

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
        
        void maxBandwidthAlgorithm(int, int);
        
    
};

#endif /* GRAPH_H */

