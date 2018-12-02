/**
*@author Nick Jordy
*@brief Graph Declaration
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>

#define SIZE 100

using namespace std;

class Graph 
{
    private:
        int numVert; //number of vertices
        int graph[SIZE][SIZE]; //the adj table
        bool* visited;//used by maxBandwidthAlgorithm
        int *path; //used by maxBandwidthAlgorithm
 
        
        int minPath(int[], bool[]);// used for Dijkstra's
        void findAllPaths(int, int, int, ofstream&);//used by maxBandwidthAlgorithm
        
    
    public:
        Graph(); //default
        Graph(int); //constructor
        ~Graph(); //deconstructor
        
        void addEdge(int, int, int); //adds an edge to the graph
        void print(); //prints the adj table
        
        void maxBandwidthAlgorithm(int, int);//finds the path with the best bandwidth 
        void DijkstraAlgorithm(int, int);//finds shrotest path between a src node and a dest node
        
    
};

#endif /* GRAPH_H */

