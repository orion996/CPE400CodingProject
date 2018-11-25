/**
*@author Nick Jordy
*@brief Graph Data Structure Implementation
*/

#include "graph.h"


//******EDGE FUNCTIONS*******

/**
 * @brief 
 * @param 
 * @return
 */
Edge::Edge(Vertex *a, Vertex *b, int dist)
{
}

/**
 * @brief 
 * @param 
 * @return
 */
Edge::~Edge()
{
}

/**
 * @brief 
 * @param 
 * @return
 */
Vertex Edge::getOrigin()
{
}

/**
 * @brief 
 * @param 
 * @return
 */
Vertex Edge::getDestination()
{
}

/**
 * @brief 
 * @param 
 * @return
 */
int Edge::getDistance()
{
}

//***************************


//******VERTEX FUNCTIONS*******

/**
 * @brief 
 * @param 
 * @return
 */
Vertex::Vertex(string str)
{
}

/**
 * @brief 
 * @param 
 * @return
 */
Vertex::~Vertex()
{
}

/**
 * @brief 
 * @param 
 * @return
 */
void Vertex::addEdge(Vertex *vert, int dist)
{
}

/**
 * @brief 
 * @param 
 * @return
 */
void Vertex::printEdges()
{
}

/**
 * @brief 
 * @param 
 * @return
 */
string Vertex::getName()
{
}

/**
 * @brief 
 * @param 
 * @return
 */
vector<Edge> Vertex::getEdges()
{
}

//***************************


//******GRAPH FUNCTIONS*******

/**
 * @brief 
 * @param 
 * @return
 */
Graph::Graph()
{
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
 * @return
 */
void Graph::insertNode(Vertex *vert)
{
}

/**
 * @brief 
 * @param 
 * @return
 */
void Graph::printGraph()
{
}

//***************************