//
// Created by Alperen Alkan on 8.05.2021.
//
/**
* Title: Balanced Search Trees, Hashing and Graphs * Author: Name Surname
* ID: 21803216
* Section: 3
* Assignment: 4
 * alperen alkan
*/
#include "HashTable.h"
#ifndef INC_21803216_HW4_WORDNETWORK_H
#define INC_21803216_HW4_WORDNETWORK_H


class WordNetwork {
public:
    WordNetwork(const string vertexFile , const string edgeFile);
    ~WordNetwork();
    void listNeighbors(const string word);
    void listNeighbors(const string word, const int distance); void listConnectedComponents();
    void findShortestPath(const string word1, const string word2);
private:
// define your data members here
// define private member functions here, if any
// you MUST use the adjacency matrix representation
    bool** matrix;
    HashTable hashTable;
    bool notNeighbor(int index, int j);
    bool bfs();
};

#endif //INC_21803216_HW4_WORDNETWORK_H
