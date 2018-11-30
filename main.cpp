/**
*@author Nick Jordy
*@brief Main running file for the CPE400 coding assignment
*/

#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"

using namespace std;

void createGraph(string, Graph*);

int main()
{
    const int numVert = 9;
    Graph network(numVert);
    
    createGraph("graphData.txt",&network);
    
    network.print();
    
    return 0;
}

/**
 * @brief
 * @param
 * @return
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
    
    ifstream fin;
    fin.open(filename.c_str());
    
    if(!fin.good())
    {
        cerr << "ERROR: FILE PATH '" << filename << "' COULD NOT BE OPENED" << endl;
        return;
    }
    
    int vertA, vertB, cost, numEdges;
    string gbg;
    
    fin >> gbg >> numEdges >> gbg;
    
    for(int i ; i<numEdges ; i++)
    {
        if(fin.eof())
            break;
        fin >> vertA >> vertB >> cost;
        //cout << vertA << " " << vertB << " " << cost << endl;
        network->addEdge(vertA, vertB, cost);
    }
    
    fin.close();
    
}
