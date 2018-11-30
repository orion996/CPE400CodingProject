/**
*@author Nick Jordy
*@brief Graph Implementation
*/

#include "graph.h"

/**
 * @brief
 * @param
 * @return
 */
Graph::Graph()
{
    numVert = 1;
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

/**
 * @brief
 * @param
 * @return
 */
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

/**
 * @brief
 * @param
 * @return
 */
Graph::~Graph()
{
    delete visited;
}
  
/**
 * @brief
 * @param
 * @return
 */
void Graph::addEdge(int a, int b, int cost)
{
    if(a > numVert || b > numVert || a < 0 || b < 0 )
        cerr << "ERROR: INVALID EDGE" << "A=" << a << " B=" << b << endl;
    else
        graph[a][b] = cost;
}

/**
 * @brief
 * @param
 * @return
 */
void Graph::print()
{
    cout << "Graph Adj Table:" << endl;
    cout << "Index starts at [0][0]" << endl << "Value at [i][j] shows the cost of the edge between Nodes i and j" << endl;
    for(int i=0 ; i<numVert ; i++)
    {
        for(int j=0 ; j<numVert ; j++)
            cout << graph[i][j] << " | ";
        cout << endl;
    }
}

/**
 * @brief
 * @param
 * @return
 */
void Graph::maxBandwidthAlgorithm(int src, int dest)
{
}