/**
*@author Nick Jordy
*@brief Graph Data Structure Implementation
*/

#include "graph.h"


//******EDGE FUNCTIONS*******

/**
 * @brief Edge Default Constructor
 * @param none
 * @return Nothing
 */
Edge::Edge()
{
    origin = NULL;
    destination = NULL;
    distance = 0;
}

/**
 * @brief Edge Constructor
 * @param *a Pointer to first vertex of edge
 * @param *b Pointer to second second of edge
 * @return Nothing
 */
Edge::Edge(Vertex *a, Vertex *b, int dist)
{
    origin = a;
    destination = b;
    distance = dist;
}

/**
 * @brief Deconstructor of Edge
 * @param none
 * @return Nothing
 */
Edge::~Edge()
{
//     delete origin;
//     delete destination;
//     origin = NULL;
//     destination = NULL;
}

/**
 * @brief Returns the value of origin
 * @param none
 * @return Value of origin
 */
Vertex* Edge::getOrigin()
{
    return origin;
}

/**
 * @brief Returns the value of destination
 * @param none
 * @return Value of destination
 */
Vertex* Edge::getDestination()
{
    return destination;
}

/**
 * @brief Returns the value of distance
 * @param none
 * @return Value of distance
 */
int Edge::getDistance()
{
    return distance;
}

//***************************


//******VERTEX FUNCTIONS*******

/**
 * @brief Default Constructor for Vertex
 * @param none
 * @return Nothing
 */
Vertex::Vertex()
{
    //do nothing
}

/**
 * @brief Constructor for Vertex
 * @param str The name of the vertex
 * @return Nothing
 */
Vertex::Vertex(const string str)
{
    name = str;
}

/**
 * @brief Deconstructor for Vertex
 * @param none
 * @return Nothing
 */
Vertex::~Vertex()
{
    //edges.clear();
}

/**
 * @brief Adds an edge between the current vertex and the one passed in with a distance "dist"
 * @param *vert the vertex to connect the edge to
 * @param dist the distance between the vertices
 * @return Nothing
 */
void Vertex::addEdge(Vertex *vert, int dist)
{
    Edge e(this, vert, dist);
    
    edges.push_back(e);
}

/**
 * @brief Prints the vertex and all vertices connected to it
 * @param none
 * @return Nothing
 */
void Vertex::printEdges()
{
    cout << name << "'s Edges: " << endl;
    
    
    for(int i=0 ; i<edges.size(); i++)
    {
        Edge temp = edges[i];
        cout << "   " << temp.getDestination()->getName() << " - " << temp.getDistance() << endl;
    }
    cout << endl;
}


/**
 * @brief prints the vertex name
 * @param none 
 * @return Nothing
 */
void Vertex::printName()
{
    cout << name << endl;
}

/**
 * @brief Returns the value of name
 * @param none
 * @return Value of name
 */
string Vertex::getName()
{
    return name;
}

/**
 * @brief Returns the vector of edges
 * @param none
 * @return vector of edges
 */
vector<Edge> Vertex::getEdges()
{
    return edges;
}

//***************************


//******GRAPH FUNCTIONS*******

/**
 * @brief Default Constructor for Graph
 * @param none
 * @return Nothing
 */
Graph::Graph()
{
    //nothing to be done
}

/**
 * @brief Deconstructor for Graph
 * @param none
 * @return Nothing
 */
Graph::~Graph()
{
    vertices.clear();
}

/**
 * @brief Inserts a vertex onto the graph
 * @param *vert the vertex to be inserted 
 * @return Nothing
 */
void Graph::insertNode(Vertex *vert)
{
    vertices.push_back(vert);
}

/**
 * @brief Prints the Graph
 * @param none
 * @return Nothing
 */
void Graph::printGraph()
{
    for(int i=0 ; i<vertices.size(); i++)
        vertices[i]->printEdges();
}

//***************************