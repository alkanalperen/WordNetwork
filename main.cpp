/**
* Title: Balanced Search Trees, Hashing and Graphs * Author: Name Surname
* ID: 21803216
* Section: 3
* Assignment: 4
 * alperen alkan
*/
#include <iostream>
#include "WordNetwork.h"

int main() {
    cout << "Hello, World!" << std::endl;
    WordNetwork wordNetwork("words_vertices.txt","words_edges.txt");
    cout << endl << endl;
    wordNetwork.listNeighbors("roger");
    cout << endl << endl;
    wordNetwork.listNeighbors("aided",4);
    cout << endl << endl;
    wordNetwork.listConnectedComponents();
    cout << endl << endl;
    wordNetwork.findShortestPath("nodes","graph");
    return 0;
}
