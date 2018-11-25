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
 
       Vertex rA("Router A");
       Vertex rB("Router B");
       Vertex rC("Router C");
       
       rA.addEdge(&rB, 50);
       rB.addEdge(&rC, 25);
       rC.addEdge(&rA, 75);
       
    Graph gr;
    
    gr.insertNode(&rB);
    gr.insertNode(&rA);
    gr.insertNode(&rC);
    
    gr.printGraph();
    
    return 0;
}

