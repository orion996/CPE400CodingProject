#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

class Edge
{
    public:
        Edge(Vertex *a, Vertex *b, , int dist);
        ~Edge();
        
        Vertex getOrigin();
        Vertex getDestination();
        int getDistance();
        
    private:
        Vertex *origin;
        Vertex *destination;
        int distance;
};


#endif /*EDGE_H*/