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
#include "Word.h"
Word::Word() {
    name = "";
    index = 0;
    marked = false;
}
Word::Word(string name, int index,bool marked) {
    this->name = name;
    this->index = index;
    this->marked = marked;
}

const string &Word::getName() const {
    return name;
}

void Word::setName(const string &name) {
    Word::name = name;
}

int Word::getIndex() const {
    return index;
}

void Word::setIndex(int index) {
    Word::index = index;
}

Word::Word(const Word& word) {
    index = word.index;
    name = word.name;
    marked = word.marked;
}