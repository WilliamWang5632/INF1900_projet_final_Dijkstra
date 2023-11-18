// questions: plusieurs poteaux possibles?
// peuvent-ils enlever des poteaux

#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"
#include "Path.cpp"
#include "createPlayground.cpp"
#include "Dijkstra.cpp"

#include "memoryDebug.cpp"

using namespace std;

int main(){
    string separationLine = "\n_________________________________________________________\n";
    // important before testing
    // change NODES_PER_ROW in Node.cpp to 7

    // playground of final test
    Graph playground = createPlayground();
    
    playground.displayMatrix();
    cout << endl;

    cout << endl;
    cout << "Before removing node: " << endl;
    playground.displayList();

    // instanciate removed nodes
    Node n62 = Node(6,2);
    Node n33 = Node(3,3);
    Node n32 = Node(3,2);

    // removing some nodes from the playground
    playground.removeNode(n62);
    playground.removeNode(n33);
    playground.removeNode(n32);
    cout << endl;
  
    cout << "After removing node: " << endl;
    playground.displayList();
    cout << endl;

    int nNodes = playground.nNodes;

    cout << separationLine << endl;
    // DIJKSTRA'S ALGORITHM

    // instanciate start and end node
    Node n14 = Node(1,4);
    Node n74 = Node(7,4);

    Path minimumCostPath = computeDijkstra(playground, n14, n74);

    // print(true) -> identifier
    // print(false)) -> identifier

    minimumCostPath.print(true);
    cout << separationLine << endl;
    minimumCostPath.print(false);

    PrintMemoryUsage();
}
