/**
*@author Nick Jordy
*@brief Graph Declaration
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

#define SIZE 50

using namespace std;

struct BW //bandwidth
{
    int path;
    int bandwidth;
};

class Graph 
{
    private:
        int numVert; //number of vertices
        int graph[SIZE][SIZE]; //the adj table
        bool* visited;//used by findAllPaths
        int *path; //used by findAllPaths
        int pathsList[SIZE][SIZE];//used by maxBandwidthAlgorithm
        
        int minPath(int[], bool[]);// used by DijkstraAlgorithm
        void findAllPaths(int, int, int, ofstream&);//used by maxBandwidthAlgorithm
        int findPathBandwidth(int[], int);//used by maxBandwidthAlgorithm
        
    
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

