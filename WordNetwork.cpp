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
#include <sstream>
#include <fstream>
#include "WordNetwork.h"
#include "Queue.h"
#include "Stack.h"

WordNetwork::WordNetwork(const string vertexFile, const string edgeFile) {
    ifstream fileVertex(vertexFile);
    ifstream fileEdge(edgeFile);

    string word;
    string line;
    string str;

    int index = 0;
    //initiliaze the arr
    //first insert the hash table by reading file and fill the arr
    while (getline(fileVertex, word, '\n')) {
        Word w(word,index,false);//create word
        hashTable.insert(w);// insert into hash table
        index++;
    }
    //create an space in the heap, first create int* point array then this pointers will point to an array
    matrix = new bool*[5757];
    for ( int i = 0; i < 5757; i++){
        matrix[i] = new bool[5757];
    }
    //matrix
    int indexOfFirst;
    int indexOfSecond;

    while (getline(fileEdge, line, '\n')) {
        istringstream stringLine(line);
        getline(stringLine, str, ',');
        indexOfFirst = hashTable.getIndex(str);
        getline(stringLine, str,'\n');
        indexOfSecond = hashTable.getIndex(str);
        if(indexOfSecond <= 5756 && indexOfFirst <= 5756 && indexOfSecond >= 0 && indexOfFirst >= 0) {
            matrix[indexOfFirst][indexOfSecond] = true;
            matrix[indexOfSecond][indexOfFirst] = true;
          //  matrix[indexOfSecond][indexOfFirst] = 1;
        }
    }

}
void WordNetwork::listNeighbors(const string word) {
    cout <<" Neighbors of "<< word<< ":"<<endl;
    int index = hashTable.getIndex(word);
    for (int i = 0; i < 5756; i++){
        if(matrix[index][i]) {
            cout << hashTable.getWord(i).getName()<< " ";
        }
    }
}
void WordNetwork::listNeighbors(const string word, const int distance) {
    //first we need distance array
    int arr[5756];
    for(int i = 0; i < 5756; i++)
        arr[i] = -2;

    Queue q;
    int i = hashTable.getIndex(word);
    q.enqueue(hashTable.getWord(i));
    hashTable.getWord(i).marked = true;
    arr[i] = 0;
    while(!q.isEmpty()){
        Word w;
        q.dequeue(w);
        for(int j = 0; j < 5756; j++){
            if(matrix[w.getIndex()][j]){
                if( !hashTable.getWord(j).marked){
                    arr[j] = arr[w.getIndex()] + 1;
                    hashTable.getWord(j).marked = true;
                    q.enqueue(hashTable.getWord(j));
                }
            }

        }
    }
    for(int j = 0; j < 5756; j++){
        if(arr[j] == distance)
            cout << hashTable.getWord(j).getName() << " ";
    }
}
bool WordNetwork::notNeighbor(int index, int j) {
    return !matrix[index][j];
}
void WordNetwork::listConnectedComponents(){
    // mark all nodes as unvisited
    for(int i = 0; i < 5756; i++){
        hashTable.getWord(i).marked = false;
    }
    int ind = 0;
    for ( int i = 0; i < 5756; i++){
        if(!hashTable.getWord(i).marked){
            Queue q;
            q.enqueue(hashTable.getWord(i));
            hashTable.getWord(i).marked = true;
            cout << "COmponent" << ind;
            ind ++;
            while(!q.isEmpty()){
                Word w;
                q.dequeue(w);
                cout << w.getName() << " ";
                for(int j = 0; j < 5756; j++){
                    if(matrix[w.getIndex()][j]){
                        if( !hashTable.getWord(j).marked)
                        {
                            hashTable.getWord(j).marked = true;
                            q.enqueue(hashTable.getWord(j));
                        }
                    }
                }
            }
            cout  << endl << endl;
        }
    }
}
void WordNetwork::findShortestPath(const string word1, const string word2) {
    cout << "shortest part: from " << word1 << " to " << word2  <<endl;
    cout << word1 << " ";
    // mark all nodes as unvisited
    for(int i = 0; i < 5756; i++){
        hashTable.getWord(i).marked = false;
    }
    //predestionation array
    string pre[5756];
    //first we need distance array
    int arr[5756];
    for(int i = 0; i < 5756; i++)
        arr[i] = -2;

    Queue q;
    int i = hashTable.getIndex(word1);
    q.enqueue(hashTable.getWord(i));
    hashTable.getWord(i).marked = true;
    arr[i] = 0;
    while(!q.isEmpty()){
        Word w;
        q.dequeue(w);
        for(int j = 0; j < 5756; j++){
            if(matrix[w.getIndex()][j]){
                if( !hashTable.getWord(j).marked){
                    arr[j] = arr[w.getIndex()] + 1;
                    pre[j] = w.getName();
                    hashTable.getWord(j).marked = true;
                    q.enqueue(hashTable.getWord(j));
                }
            }

        }
    }
    string path[5756];
    string w = word2;
    path[0] = w;
    int index = 1;
    while (pre[hashTable.getIndex(w)] != word1) {
        //find min
        path[index] = pre[hashTable.getIndex(w)];
        w = pre[hashTable.getIndex(w)];
        index++;
    }
    for (int i = index-1 ; i >= 0; i--)
        cout << path[i] << " ";
}
WordNetwork::~WordNetwork(){
    for(int i = 0; i < 5756; ++i) {
            delete[] matrix[i];
        }
        //Free the array of pointers
        delete[] matrix;

}
