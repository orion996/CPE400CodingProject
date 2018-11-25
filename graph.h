/**
*@author Nick Jordy
*@brief Graph Data Structure header
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Edge;

class Vertex 
{
    public:
        Vertex(string str);
        ~Vertex();
        
        void addEdge(Vertex *vert, int dist);
        void printEdges();
        
        string getName();
        vector<Edge> getEdges();
        
    private:
        string name;
        vector<Edge> edges;
};

class Edge
{
    public:
        Edge(Vertex *a, Vertex *b, int dist);
        ~Edge();
        
        Vertex getOrigin();
        Vertex getDestination();
        int getDistance();
        
    private:
        Vertex *origin;
        Vertex *destination;
        int distance;
};



class Graph 
{
    public:
        Graph();
        ~Graph();
        
        void insertNode(Vertex *vert);
        void printGraph();
        
    private:
        vector<Vertex*> vertices;
};

#endif /*GRAPH_H*/