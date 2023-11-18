#include <iostream>
#include "Node.cpp"
#include "Edge.cpp"
#include "Graph.cpp"
#include "Path.cpp"
#include "createPlayground.cpp"

using namespace std;

const int INF = 255; // very large number representing infinity

struct DijkstraResult{
    int* nodeArr; // array of integers representing the ids of the computed path
    int size;     // number of nodes in path
    int pathCost; // cost of path

    // print struct attributes
    void print(){
        cout << "Fastest path from node " << nodeArr[0] << " to node " << nodeArr[size - 1] << ": " << endl;
        for (int i = 0; i < size; i++){
            cout << nodeArr[i] << " -> ";
        }
        cout << "end" << endl;
        cout << "total cost: " << pathCost << endl;
    }
};

/**
 *  this function computes the shortest path between a starting and ending node in a graph
    @param adjacencyMatrix 2D matrix representing adjacency between all nodes of a graph
    @param nNodes number of nodes inside of graph
    @param start starting node
    @param end ending node
    @return struct of type DijkstraResult 
*/

DijkstraResult computeDijkstra(int** adjacencyMatrix, int nNodes, Node& start, Node& end) {
    // Initialize distanceArr and visitedArr arrays
    int* distanceArr = new int[nNodes];
    bool* visitedArr = new bool[nNodes];
    int* previousNodes = new int[nNodes];

    for (int i = 0; i < nNodes; i++) {
        distanceArr[i] = INF;   // distance to all other nodes = infinity
        visitedArr[i] = false;  // no nodes have been visited yet
        previousNodes[i] = -1;
    }

    // distance from start to itself is 0 
    distanceArr[start.id] = 0;

    // Dijkstra's algorithm
    for (int i = 0; i < nNodes-1; i++) {
        // Find the minimum distance node that hasn't been utilised yet
        int cur = -1;
        for (int j = 0; j < nNodes; j++) {
            if (!visitedArr[j] && (cur == -1 || distanceArr[j] < distanceArr[cur])) {
                cur = j;
            }
        }

        // Mark the current node as visited
        visitedArr[cur] = true;

        // Update the distanceArr value of the adjacent nodes
        for (int adj = 0; adj < nNodes; ++adj) {
            if (!visitedArr[adj] && adjacencyMatrix[cur][adj] != -1 && distanceArr[cur] != INF &&
                distanceArr[cur] + adjacencyMatrix[cur][adj] < distanceArr[adj]) {
                distanceArr[adj] = distanceArr[cur] + adjacencyMatrix[cur][adj];
                previousNodes[adj] = cur;
            }
        }
    }

    int* path = new int[nNodes];
    int pathLength = 0;
    int current = end.id;

    while (current != -1){
        pathLength++;
        path[pathLength] = current;
        current = previousNodes[current];
    }

    int* finalNodeArray = new int[pathLength];
    int j = 0;
    for (int i = pathLength; i >= 0; i--){
        if (path[i] >= 0){
            finalNodeArray[j] = path[i];
            j++;
        }
    }

    DijkstraResult dijkstraResult;
    dijkstraResult.nodeArr = finalNodeArray;
    dijkstraResult.size = pathLength;
    dijkstraResult.pathCost = distanceArr[end.id];

    return dijkstraResult;

    // free dynamically allocated memory
    delete[] distanceArr;
    delete[] visitedArr;
    delete[] previousNodes;
    delete[] path;
    delete[] finalNodeArray;

}

