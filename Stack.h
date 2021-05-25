//
// Created by Alperen Alkan on 11.05.2021.
//
/**
* Title: Balanced Search Trees, Hashing and Graphs * Author: Name Surname
* ID: 21803216
* Section: 3
* Assignment: 4
 * alperen alkan
*/
#ifndef INC_21803216_HW4_STACK_H
#define INC_21803216_HW4_STACK_H


#include "Word.h"

class Stack {
public:
public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();

    bool isEmpty() const;
    bool push(Word newItem);
    bool pop();
    bool pop(Word& stackTop);
    bool getTop(Word& stackTop) const;

private:
    struct WordNode {            // a node on the stack
        Word item;        // a data item on the stack
        WordNode    *next;        // pointer to next node
    };

    WordNode *topPtr;     // pointer to first node in the stack

};


#endif //INC_21803216_HW4_STACK_H
