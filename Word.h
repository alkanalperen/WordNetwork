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
#ifndef INC_21803216_HW4_WORD_H
#define INC_21803216_HW4_WORD_H
#include <iostream>
using namespace std;


class Word {
private:
    string name;
    int index;

public:
    Word();
    bool marked;

    Word(string name, int index, bool marked);

    Word(const Word& word);

    const string &getName() const;

    void setName(const string &name);

    int getIndex() const;

    void setIndex(int index);
};


#endif //INC_21803216_HW4_WORD_H
