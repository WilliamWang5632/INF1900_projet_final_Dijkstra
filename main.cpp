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
    // important before testing
    // change nodesPerRow in Node.cpp to 7

    // aire de jeu du Projet Final
    Node n11 = Node(1,1);
    Node n21 = Node(2,1);
    Node n31 = Node(3,1);
    Node n41 = Node(4,1);
    Node n51 = Node(5,1);
    Node n61 = Node(6,1);
    Node n71 = Node(7,1);
    
    // row 2
    Node n12 = Node(1,2);
    Node n22 = Node(2,2);
    Node n32 = Node(3,2);
    Node n42 = Node(4,2);
    Node n52 = Node(5,2);
    Node n62 = Node(6,2);
    Node n72 = Node(7,2);
    
    // row 3
    Node n13 = Node(1,3);
    Node n23 = Node(2,3);
    Node n33 = Node(3,3);
    Node n43 = Node(4,3);
    Node n53 = Node(5,3);
    Node n63 = Node(6,3);
    Node n73 = Node(7,3);
    
    // row 4
    Node n14 = Node(1,4);
    Node n24 = Node(2,4);
    Node n34 = Node(3,4);
    Node n44 = Node(4,4);
    Node n54 = Node(5,4);
    Node n64 = Node(6,4);
    Node n74 = Node(7,4);

    // weight of each color
    
    int black = 1;
    int yellow = 2;
    int red = 3;
    
    // instanciation of edges
    
    // instanciation of horizontal edges
    
    // row 1 horizontal edges
    Edge e11_21 = Edge(black, n11, n21);
    Edge e21_31 = Edge(black, n21, n31);
    Edge e31_41 = Edge(black, n31, n41);
    Edge e51_61 = Edge(black, n51, n61);
    Edge e61_71 = Edge(black, n61, n71);
    
    // row 2 horizontal edges
    Edge e12_22 = Edge(red, n12, n22);
    Edge e22_32 = Edge(black, n22, n32);
    Edge e42_52 = Edge(yellow, n42, n52);
    Edge e52_62 = Edge(black, n52, n62);
    Edge e62_72 = Edge(black, n62, n72);
    
    // row 3 horizontal edges    
    Edge e13_23 = Edge(yellow, n13, n23);
    Edge e23_33 = Edge(black, n23, n33);
    Edge e33_43 = Edge(black, n33, n43);
    Edge e43_53 = Edge(red, n43, n53);
    
    // row 4 horizontal edges    
    Edge e14_24 = Edge(black, n14, n24);
    Edge e24_34 = Edge(black, n24, n34);
    Edge e44_54 = Edge(yellow, n44, n54);
    Edge e54_64 = Edge(red, n54, n64);
    Edge e64_74 = Edge(black, n64, n74);
    
    // instanciation of vertical edges
    
    // column 1 vertical edges
    Edge e11_12 = Edge(black, n11, n12);
    Edge e13_14 = Edge(red, n13, n14);
    
    // column 2 vertical edges
    Edge e22_23 = Edge(black, n22, n23);
    
    // column 3 vertical edges    
    Edge e31_32 = Edge(black, n31, n32);
    Edge e32_33 = Edge(red, n32, n33);
    Edge e33_34 = Edge(black, n33, n34);
    
    // column 4 vertical edges
    Edge e41_42 = Edge(black, n41, n42);
    Edge e43_44 = Edge(black, n43, n44);
    
    // column 5 vertical edges
    Edge e52_53 = Edge(red, n52, n53);
    Edge e53_54 = Edge(red, n53, n54);
    
    // column 6 vertical edges
    Edge e61_62 = Edge(yellow, n61, n62);
    Edge e62_63 = Edge(black, n62, n63);
    Edge e63_64 = Edge(black, n63, n64);
    
    // column 7 vertical edges
    Edge e71_72 = Edge(black, n71, n72);
    Edge e72_73 = Edge(black, n72, n73);
    Edge e73_74 = Edge(black, n73, n74);
    
    
    
    //e12_13.printInfo();
    Graph playground = Graph(28);
    
    PrintMemoryUsage();
    
    // adding edges to playground
    
    // adding horizontal edges to playground
    
    // adding row 1 horizontal edges to graph
    playground.addEdge(e11_21);
    playground.addEdge(e21_31);
    playground.addEdge(e31_41);
    playground.addEdge(e51_61);
    playground.addEdge(e61_71);

    // adding row 2 horizontal edges to graph  
    playground.addEdge(e12_22);
    playground.addEdge(e22_32);
    playground.addEdge(e42_52);
    playground.addEdge(e52_62);
    playground.addEdge(e62_72);
    
    // adding row 3 horizontal edges to graph  
    playground.addEdge(e13_23);
    playground.addEdge(e23_33);
    playground.addEdge(e33_43);
    playground.addEdge(e43_53);
    
    // adding row 4 horizontal edges to graph  
    playground.addEdge(e14_24);
    playground.addEdge(e24_34);
    playground.addEdge(e44_54);
    playground.addEdge(e54_64);
    playground.addEdge(e64_74);
    
    // adding vertical edges to playground
    
    // adding column 1 vertical edges to graph  
    playground.addEdge(e11_12);
    playground.addEdge(e13_14);
    
    // adding column 2 vertical edges to graph  
    playground.addEdge(e22_23);
    
    // adding column 3 vertical edges to graph  
    playground.addEdge(e31_32);
    playground.addEdge(e32_33);
    playground.addEdge(e33_34);
    
    // adding column 4 vertical edges to graph  
    playground.addEdge(e41_42);
    playground.addEdge(e43_44);
    
    // adding column 5 vertical edges to graph  
    playground.addEdge(e52_53);
    playground.addEdge(e53_54);
    
    // adding column 6 vertical edges to graph  
    playground.addEdge(e61_62);
    playground.addEdge(e62_63);
    playground.addEdge(e63_64);
    
    // adding column 7 vertical edges to graph  
    playground.addEdge(e71_72);
    playground.addEdge(e72_73);
    playground.addEdge(e73_74);
    
    playground.displayMatrix();
    cout << endl;

    //creating a path

    Path path1 = Path(n11, playground);
    //path1.checkAvailableNextNode();
    path1.moveTo(n21);
    path1.moveTo(n31);
    path1.moveTo(n32);
    path1.moveTo(n33);
    path1.moveTo(n43);
    path1.moveTo(n44);
    path1.moveTo(n54);
    path1.moveTo(n64);
    path1.moveTo(n74);

    path1.showPath();

    cout << endl;
    // creating another path

    //PrintMemoryUsage();

    Path path2 = Path(n11, playground);

    //path1.checkAdjacentNodes();
    path2.moveTo(n21);
    path2.moveTo(n31);
    path2.moveTo(n41);
    path2.moveTo(n42);
    path2.moveTo(n52);
    path2.moveTo(n62);
    path2.moveTo(n72);
    path2.moveTo(n73);
    path2.moveTo(n74);

    path2.showPath();

    cout << endl;
    //create third path

    Path path3 = Path(n71, playground);
    
    path3.moveTo(n72);
    path3.moveTo(n62);
    path3.moveTo(n52);
    path3.moveTo(n42);
    path3.moveTo(n41);
    path3.moveTo(n31);
    path3.moveTo(n32);
    path3.moveTo(n22);
    path3.moveTo(n23);
    path3.moveTo(n33);
    path3.moveTo(n34);
    path3.moveTo(n24);
    path3.moveTo(n14);

    path3.showPath();

    cout << endl;
    cout << "Before removing node: " << endl;
    playground.displayList();
    playground.removeNode(n62); // remove node with id: 12 from graph
    playground.removeNode(n33);
    playground.removeNode(n32);
    cout << endl;
    
    // affected nodes: 5, 11, 13, 19
    cout << "After removing node: " << endl;
    playground.displayList();
    cout << endl;

    int** adjMatrix = playground.adjacencyMatrix;
    int nNodes = playground.nNodes;

    // DIJKSTRA'S ALGORITHM

    DijkstraResult dijkstraResult = computeDijkstra(adjMatrix, nNodes, n14, n74);

    dijkstraResult.print();

    PrintMemoryUsage();
}
