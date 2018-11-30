#include "graph.h"

Graph::Graph()
{
}

Graph::Graph(int n)
{
    numVert = n;
    visited = new bool[numVert];
    //graph = new int*[numVert];
    
    for(int i=0 ; i<SIZE ; i++)
    {
        //graph[i] = new int[numVert];
        for(int j=0 ; j<SIZE ; j++)
        {
            graph[i][j] = 0;
        }
    }
}

Graph::~Graph()
{
}
        
void Graph::addEdge(int a, int b, int cost)
{
    if(a > numVert || b > numVert || a < 0 || b < 0 )
        cerr << "ERROR: INVALID EDGE" << "A=" << a << " B=" << b << endl;
    else
        graph[a][b] = cost;
}
void Graph::print()
{
    for(int i=0 ; i<numVert ; i++)
    {
        for(int j=0 ; j<numVert ; j++)
            cout << graph[i][j] << "    ";
        cout << endl;
    }
}