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
#ifndef INC_21803216_HW4_HASHTABLE_H
#define INC_21803216_HW4_HASHTABLE_H


#include "Word.h"

class HashTable {
public:
    HashTable();

    ~HashTable();

    void insert(Word word);

    int getIndex(string key);

    int hash(const string& key) const;

    void displayHash();

    Word& getWord(int index);


private:
    struct WordNode {
        Word word;
        WordNode* next;
    };
    int tableSize;
    WordNode* hashTable;

};



#endif //INC_21803216_HW4_HASHTABLE_H
