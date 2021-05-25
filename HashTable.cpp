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
const int TABLESIZE = 107;

#include "HashTable.h"
HashTable::HashTable() {
    hashTable = new WordNode[TABLESIZE];
}
HashTable::~HashTable() {
    delete[] hashTable;
}
int HashTable::getIndex(string key) {
    int hashVal = hash(key);
    WordNode* cur = &hashTable[hashVal];
        if (cur->word.getName() == key) {
            return cur->word.getIndex();
        }
        while (cur->next != NULL) {
            if (cur->next->word.getName() == key) {
                return cur->next->word.getIndex();
            }
            cur = cur->next;
        }

}
void HashTable::insert(Word word) {
    int hashVal = hash(word.getName());
    WordNode* newNode = new WordNode();
    newNode->word = word;
   // newNode->next = NULL;
// check the beggining of the linked list is empy
    if(hashTable[hashVal].word.getName() == ""){
        hashTable[hashVal] = *newNode;
    }else{
        WordNode* cur = &hashTable[hashVal];
        while(cur->next !=NULL){
            cur = cur->next;
        }
        cur->next = newNode;
        cur = cur->next;
    }
}
int HashTable::hash(const string& key) const {
    int hashVal = 0;

    for (int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];

    hashVal %=TABLESIZE;
    if (hashVal < 0)   /* in case overflows occurs */
        hashVal += TABLESIZE;

    return hashVal;

}

void HashTable::displayHash() {
    for(int i = 0; i <TABLESIZE; i++){
        cout << i;
        if(hashTable[i].word.getName()!="") {
            WordNode *cur = &hashTable[i];
            cout << " --> " << cur->word.getName();
            while(cur->next != NULL){
                cur = cur->next;
                cout << " --> " << cur->word.getName();
            }
        }
        cout << endl;

    }
}

Word& HashTable::getWord(int index) {
    //traverse hash table
    for(int i = 0; i <TABLESIZE; i++){
        if(hashTable[i].word.getName()!="") {
            WordNode *cur = &hashTable[i];
            if(cur->word.getIndex() == index)
                return cur->word;
            while(cur->next != NULL){
                cur = cur->next;
                if(cur->word.getIndex() == index)
                    return cur->word;
            }
        }
    }
}
