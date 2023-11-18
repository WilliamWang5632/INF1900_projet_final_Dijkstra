#pragma once
#include <iostream>

using namespace std;

// number of nodes per line
const int nodesPerRow = 7; //7

// example of instanciation:
// Node n21 = Node(2, 1);

class Node{
public:
    // default constructor
    Node(){
        id = 0;  
        x_position = 1;
        y_position = 1;
        is_available = true;
    }

    /** Node constructor with parameters
    @param x x coordinate of Node instance
    @param y y coordinate of Node instance
    */
    Node(int x, int y){
        x_position = x;
        y_position = y;
        is_available = true;
        id = nodesPerRow * (y - 1) + x - 1;
    }
    /*
    prints Node id, x coordinate and y coordinate
    */
    void printInfo(){
        cout << "id: " << id << endl;
        cout << "x coordinate: " << x_position << endl;
        cout << "y coordinate: " << y_position << endl;
    }

    /*
    assignment operator overload
    */
    Node& operator=(const Node& other){
        // check if this and other have the same adress
        if (this != &other){
            id = other.id;
            x_position = other.x_position;
            y_position = other.y_position;
            is_available = other.is_available;
        }
        return *this;
    }

    /*
    overload == operator to compare 2 nodes (necessary?)
    */
    bool operator==(const Node& other) const {
        return (x_position == other.x_position) && (y_position == other.y_position);
    }
    
    int id;  
    int x_position;
    int y_position;
    bool is_available;

};