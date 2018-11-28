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
    vertices = new list<intPair>[numVert];
}

/**
 * @brief
 * @param
 * @return
 */
Graph::Graph(int vertNum)
{
    this->numVert = vertNum;
    vertices = new list<intPair>[numVert];
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
    vertices[a].push_back(make_pair(b, edge));
    vertices[b].push_back(make_pair(a, edge));
}

/**
 * @brief Prints the shortest part from srcNode to all other vertices
 * @param srcNode the source node 
 * @return Nothing
 */
void Graph::findShortestPath(int srcNode, int endNode)
{
    priority_queue< intPair, vector<intPair>, greater<intPair> > priorityQueue;
    
    vector<int> distances(numVert, INF);
    
    priorityQueue.push(make_pair(0, srcNode));
    distances[srcNode] = 0;
    
    vector<intPair>throughNodes(numVert);
    throughNodes[srcNode] = make_pair(srcNode, srcNode);
    
    while(!priorityQueue.empty())
    {
        int a = priorityQueue.top().second;
        //cout << "(" << priorityQueue.top().first << "," << priorityQueue.top().second << ")" << endl;
        priorityQueue.pop();
        
        list< pair<int, int> >::iterator i;
        for(i=vertices[a].begin() ; i!=vertices[a].end() ; i++)
        {
            int b = (*i).first;
            int cost = (*i).second;
            
            if(distances[b] > distances[a] + cost)
            {
                distances[b] = distances[a] + cost;
                priorityQueue.push(make_pair(distances[b], b));
                
            }
        }
        
    }
    //print the shortest path 
//     cout << "Vertex     Distance from Source" << endl;
//     for(int i = 0 ; i<numVert ; ++i)
//     {
//         cout << i << "\t\t" << distances[i] << endl;
//     }

    cout << "Vertex     Distance from Source" << endl;
    cout << endNode << "\t\t" << distances[endNode] << endl;
}
