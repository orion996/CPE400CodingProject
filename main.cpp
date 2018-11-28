/**
*@author Nick Jordy
*@brief Main running file for the CPE400 coding assignment
*/

#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"

using namespace std;

void DijkstraAlgorithm(Graph gr, int);

/**
 * @brief The main working functon
 * @param none
 * @return 0 if successful exit, 1 if erroneous exit
 */
int main()
{
    Graph *mesh;// the graph of routers
    mesh = new Graph();
    
    //Create Routers
    Vertex rA("A");
    Vertex rB("B");
    Vertex rC("C");
    Vertex rD("D");
    Vertex rE("E");
    Vertex rF("F");
     
    //Connect Routers
    rA.addEdge(&rB, 2);
    rA.addEdge(&rD, 1);
    
    rB.addEdge(&rA, 2);
    rB.addEdge(&rC, 1);
    rB.addEdge(&rD, 2);
    rB.addEdge(&rE, 3);
    
    rC.addEdge(&rB, 1);
    rC.addEdge(&rE, 4);
    rC.addEdge(&rF, 2);
    
    rD.addEdge(&rA, 1);
    rD.addEdge(&rB, 2);
    rD.addEdge(&rE, 3);
    
    rE.addEdge(&rB, 3);
    rE.addEdge(&rC, 4);
    rE.addEdge(&rD, 3);
    rE.addEdge(&rF, 3);
    
    rF.addEdge(&rC, 2);
    rF.addEdge(&rE, 3);
    
    //Insert Nodes into the mesh
    mesh->insertNode(&rA);
    mesh->insertNode(&rB);
    mesh->insertNode(&rC);
    mesh->insertNode(&rD);
    mesh->insertNode(&rE);
    mesh->insertNode(&rF);
    
    //Print the Graph
    mesh->printGraph();
    
    delete mesh;
    return 0;
}

/**
 * @brief
 * @param
 * @return
 */
