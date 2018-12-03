/**
*@author Nick Jordy
*@brief Graph Implementation
*/

#include "graph.h"

/**
 * @brief Default Constructor
 * @param none
 * @return Nothing
 */
Graph::Graph()
{
    numVert = 1;
    visited = new bool[numVert];
    path = new int[numVert];
    
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            graph[i][j] = 0;
            pathsList[i][j] = -1;
        }
    }
    for(int i=0 ; i<numVert ; i++)
        visited[i] = false;
}

/**
 * @brief Constructor with number of vertices of graph
 * @param n The number of vertices in the graph
 * @return Nothing
 */
Graph::Graph(int n)
{
    numVert = n;
    visited = new bool[numVert];
    path = new int[numVert];
    
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            graph[i][j] = 0;
            pathsList[i][j] = -1;
        }
    }
    
    for(int i=0 ; i<numVert ; i++)
        visited[i] = false;
}

/**
 * @brief Deconstructor
 * @param none
 * @return Nothing
 */
Graph::~Graph()
{
}
  
/**
 * @brief Adds an edge to the graph between two nodes a and b
 * @param a The id of the first node
 * @param b The id of the second node
 * @param cost The edge cost
 * @return Nothing
 */
void Graph::addEdge(int a, int b, int cost)
{
    if(a > numVert || b > numVert || a < 0 || b < 0 )
        cerr << "ERROR: INVALID EDGE" << "A=" << a << " B=" << b << endl;
    else
        graph[a][b] = cost;
}

/**
 * @brief Prints the graph's adj table
 * @param none
 * @return Nothing
 */
void Graph::print()
{
    cout << "Graph Adj Table:" << endl;
    for(int i=0 ; i<numVert ; i++)
    {
        for(int j=0 ; j<numVert ; j++)
            cout << graph[i][j] << " | ";
        cout << endl;
    }
}

/**
 * @brief Finds the the minmum path for DijkstraAlgorithm
 * @param dist[] The array of distances 
 * @param sptSet[] The Shortest Path Tree Set
 * @return The index of the shortest path in dist[]
 */
int Graph::minPath(int dist[], bool sptSet[])
{
    int min = __INT_MAX__;
    int index;
    
    for(int i=0 ; i<numVert ; i++)
    {
        if(sptSet[i] == false && dist[i]<= min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

/**
 * @brief Dijkstra's Shortest Path Algorithm to find the shotest path between two nodes
 * @param src The id of the source node
 * @param dest the id of the destination node
 * @return Nothing
 */
void Graph::DijkstraAlgorithm(int src, int dest)
{
    int dist[numVert];
    bool sptSet[numVert];
    int throughVert[numVert];
    
    for(int i=0 ; i<numVert ; i++)//initialize all to Infinity
    {
        dist[i] = __INT_MAX__;
        sptSet[i] = false;
    }
    
    dist[src] = 0; //distance of the source to the source is zero
    
    for(int i=0 ; i<numVert-1 ; i++)//find the index of the vertex with the desired path
    {
        int u = minPath(dist, sptSet);
    
        sptSet[u] = true;//add vertex u to the shortest path tree set
        
        for(int v=0 ; v<numVert ; v++)
        {
            if(!sptSet[v] && graph[u][v] && dist[u] != __INT_MAX__ && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                throughVert[v] = u;
            }
        }
    }
    
    cout << "Shortest distance from Router " << src << " to Router " << dest << " is " << dist[dest] << " through Router " << throughVert[dest] << endl;
            
}

/**
 * @brief Finds the path with the maximum bandwidth between two nodes
 * @param src The id of the source node
 * @param dest The id of the destination node
 * @return Nothing
 */
void Graph::maxBandwidthAlgorithm(int src, int dest)
{
    
    //1) Find All paths from src to dest and store them in a file
    int pathIndex = 0;
    ofstream fout;
    fout.open("pathInfo.txt");
    
    findAllPaths(src, dest, pathIndex, fout);
    
    fout.close();
    
    //2) Calculate the Max Bandwidth for each path found (bandwidth = min of all individal costs)
    ifstream fin;
    fin.open("pathInfo.txt");
    
    int pathNum = 0;
    int routerNum = 0;
    int temp = -1;
    
    while(!fin.eof())
    {
        fin >> temp;
        pathsList[pathNum][routerNum++] = temp;
        if(temp == dest)
        {
            pathNum++;
            routerNum = 0;
        }
    }
    
    pathNum--;
    
    cout << endl <<"All Possible Paths from Router " << src << " to Router " << dest << ":" << endl;
    for(int i=0 ; i<pathNum ; i++)
    {
        cout << "Path " << i << ": ";
        for(int j=0 ; j<numVert ; j++)
        {
            if(pathsList[i][j] != -1)
            {
                if(pathsList[i][j] == dest)
                    cout << pathsList[i][j];
                else
                    cout << pathsList[i][j] << " -> ";
            }
            
        }
        cout << endl;
    }
    
    int routersInPath = 0;
    BW bandwidths [pathNum]; 
    cout << endl;
    for(int i=0 ; i<pathNum ; i++)
    {
        cout << "Bandwidth of Path " << i << ": ";
        for(int j=0 ; j<numVert ; j++)
        {
            if(pathsList[i][j] != -1)
                routersInPath++;
        }
        
        bandwidths[i].path = i;
        bandwidths[i].bandwidth = findPathBandwidth(pathsList[i], routersInPath);
        
        cout << bandwidths[i].bandwidth << " bps" << endl;
        
        routersInPath = 0;
    }
    
    //3) Take the path with the max bandwidth and print it
    
    BW swapTemp;
    for(int i=0 ; i<pathNum ; i++)
    {
        for(int j=i ; j<pathNum ; j++)
        {
            if(bandwidths[i].bandwidth <= bandwidths[j].bandwidth)
            {
                swapTemp =  bandwidths[i];
                bandwidths[i] = bandwidths[j];
                bandwidths[j] = swapTemp;
            }
        }
    }
    
    cout << endl << "The path with the best Bandwidth is Path " << bandwidths[0].path << " with " << bandwidths[0].bandwidth << " bps" << endl;
    
    
}

/**
 * @brief Finds all paths between two nodes using a modified DFS Algorithm
 * @param src The id of the source node
 * @param dest The id of the destination node
 * @param pathIndex A storage of the index of the Path array used in the functon (passed as 0 on the first call)
 * @param fout The output filesteam for storage of the paths found
 * @return Nothing
 */
void Graph::findAllPaths(int src, int dest, int pathIndex, ofstream& fout)
{
    visited[src] = true;
    path[pathIndex] = src;
    pathIndex++;
    
    if(src == dest)
    {
        for(int i=0; i<pathIndex ; i++)
        {
            fout << path[i] << " ";
        }
        fout << endl;
    }
    else
    {
        for(int v=0 ; v<numVert ; v++)
        {
            if(!visited[v] && graph[src][v] > 0)
            {
                findAllPaths(v, dest, pathIndex, fout);
            }
        }
    }
    
    pathIndex--;
    visited[src] = false;
    
}

/**
 * @brief Finds the bandwidth of a path of nodes
 * @param path[] The array the path is stored in
 * @param routersInPath The number of nodes in the path
 * @return The bandwidth of the path
 */
int Graph::findPathBandwidth(int path[], int routersInPath)
{
    int bandwidth = __INT_MAX__;
    
    for(int i=0 ; i<routersInPath-1 ; i++)
    {
        bandwidth = min(bandwidth, graph[path[i]][path[i+1]]); 
    }
    
    return bandwidth;
}