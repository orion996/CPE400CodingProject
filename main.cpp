/**
*@author Nick Jordy
*@brief Main running file for the CPE400 coding assignment
*/

#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

void createGraph(string, Graph*);

/**
 * @brief The main driver function for the project
 * @param none
 * @return 0 on a successful exit
 */
int main()
{
    const int numVert = 9;
    Graph network(numVert);
    
    createGraph("graphData.txt",&network);
    
    int src = 0;
    int dest = 0;
    
    cout << "Enter the Source Router as an Integer Id (eg. '3'): ";
    cin >> src;
    
    cout << "Enter the Destnation Router as an Integer Id (eg. '3'): ";
    cin >> dest;
    
    network.print();
    network.maxBandwidthAlgorithm(src,dest);
    
    return 0;
}

/**
 * @brief Creates a graph from a file
 * @param filename The path to the config file
 * @param *network The graph to store data to
 * @return Nothing
 */
void createGraph(string filename, Graph* network)
{
//  *********HARD-CODED GRAPH***********    
//     network->addEdge(0,1,4);
//     network->addEdge(0,7,8);
//     network->addEdge(1,2,8);
//     network->addEdge(1,7,11);
//     network->addEdge(2,8,2);
//     network->addEdge(2,3,7);
//     network->addEdge(2,5,4);
//     network->addEdge(3,4,9);
//     network->addEdge(3,5,14);
//     network->addEdge(4,5,10);
//     network->addEdge(5,6,2);
//     network->addEdge(6,8,6);
//     network->addEdge(6,7,1);
//     network->addEdge(7,8,7);
    
    ifstream fin(filename.c_str());
    
    if(!fin.good())
    {
        cerr << "ERROR: FILE PATH '" << filename << "' COULD NOT BE OPENED" << endl;
        return;
    }
    
    int vertA, vertB, cost;
    string gbg;
    
    fin >> gbg;
    
    while(!fin.eof())
    {
        fin >> vertA >> vertB >> cost;
        //cout << vertA << " " << vertB << " " << cost << endl;
        network->addEdge(vertA, vertB, cost);
    }
    
    fin.close();
    
}
