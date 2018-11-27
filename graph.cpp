/**
*@author Nick Jordy
*@brief Iplementation for graph
*/

#include "graph.h"

/**
 * @brief
 * @param
 * @return
 */
Graph::Graph()
{
    numVert = 0;
    vertices = new vector<intPair>[numVert];
}

/**
 * @brief
 * @param
 * @return
 */
Graph::Graph(int vertNum)
{
    numVert = vertNum;
    vertices = new vector<intPair>[numVert];
}

/**
 * @brief
 * @param
 * @return
 */
Graph::~Graph()
{
}

/**
 * @brief
 * @param
 * @param
 * @param
 * @return
 */
void Graph::addEdge(int a, int b, int edge)
{
    vertices[a].push_back(make_pair(a, edge));
    vertices[b].push_back(make_pair(b, edge));
}

/**
 * @brief Prints the shortest part from srcNode to all other vertices
 * @param srcNode the source node 
 * @return Nothing
 */
void Graph::findShortestPath(int srcNode)
{
    priority_queue<intPair, vector<intPair>, greate<intPair>> priorityQueue;
}
