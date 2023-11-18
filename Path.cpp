#pragma once
#include <iostream>

#include <vector> // remove eventually


#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"

#include "memoryDebug.cpp"


using namespace std;

// example of instanciation
// Path path1 = Path(n11, graph1);
class Path{
public:
    // default constructor
    // single node graph with start at (1, 1)
    Path(){
        playground = Graph(1);
        start = Node(1,1);
        current = Node(1,1);
        totalCost = 0;
        nNodes = 1;

        nodeArray = new Node[1];
        nodeArray[0] = Node(1,1);
    }

    /**
     * constructor with parameters
     @param startingPoint starting node
     @param graph graph that the path will take place in
     */
    Path(Node& startingPoint, Graph& graph){
        start = startingPoint;
        current = startingPoint;
        playground = graph;
        totalCost = 0;
        nNodes = 1;

        nodeArray = new Node[1];
        nodeArray[0] = startingPoint;
    }

    /**
     * prints adjacent nodes to current node
     */ 
    void checkAdjacentNodes(){
        int currentId = current.id;
        cout << "Nodes adjacent to your current location: " << endl;
        for (int i = 0; i < playground.nNodes; i++){
            if (playground.adjacencyMatrix[i][currentId] > 0){
                cout << i << endl;
            }
        }
    }

    /**
     * if next node is adjacent to current node, move to that node
     * adds edge weight to totalCost
     * adds node to array containing all nodes in path
     @param node next node if it is valid
     */ 
    void moveTo(Node& node){
        if (playground.adjacencyMatrix[node.id][current.id] > 0){
            int weight = playground.adjacencyMatrix[node.id][current.id];
            totalCost += weight;
            current = node;
            addNode(node);
        }
        else{
            cout << "selected node is not adjacent to current node!" << endl;
        }
    }

    // print the ids of all nodes in path in order as well as the totalCost
    void showPath(){
        cout << "path: ";

        for (int i = 0; i < nNodes; i++){
            cout << nodeArray[i].id << " => ";
        }

        cout << "fin" << endl;
        cout << "There are " << nNodes - 1 << " edges in this path" << endl;
        cout << "Total cost of this path: " << totalCost << endl;
    }

    /**
     * this method is equivalent to .push_back(node)
     @param node node that will be added to nodeArray
     */ 
    void addNode(Node node) {
        int newSize = nNodes + 1;
        Node* newNodeArray = new Node[newSize];

        for (int i = 0; i < nNodes; ++i) {
            newNodeArray[i] = nodeArray[i];
        }

        newNodeArray[nNodes] = node;
        delete[] nodeArray;

        nodeArray = newNodeArray;
        nNodes = newSize;
    }

    ~Path(){
        delete[] nodeArray;
    } 

    int nNodes;
    Node* nodeArray;

    int totalCost;
    Node start;
    Node current;
    Graph playground;
};