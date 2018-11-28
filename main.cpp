/**
*@author Nick Jordy
*@brief Main running file for the CPE400 coding assignment
*/

#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"

using namespace std;


/**
 * @brief The main working functon
 * @param none
 * @return 0 if successful exit, 1 if erroneous exit
 */
int main()
{
    Graph mesh(9);
    
    mesh.addEdge(0,1,4);
    mesh.addEdge(0,7,8);
    mesh.addEdge(1,2,8);
    mesh.addEdge(1,7,11);
    mesh.addEdge(2,3,7);
    mesh.addEdge(2,8,2);
    mesh.addEdge(2,5,4);
    mesh.addEdge(3,4,9);
    mesh.addEdge(3,5,14);
    mesh.addEdge(4,5,10);
    mesh.addEdge(5,6,2);
    mesh.addEdge(6,7,1);
    mesh.addEdge(6,8,6);
    mesh.addEdge(7,8,7);
    
    mesh.findShortestPath(0, 3);
    return 0;
}

/**
 * @brief
 * @param
 * @return
 */
