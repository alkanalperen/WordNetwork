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
#include "Stack.h"

Stack::Stack() : topPtr(NULL) {

}

// copy constructor
Stack::Stack(const Stack &aStack) {

    if (aStack.topPtr == NULL)
        topPtr = NULL;  // original stack is empty

    else {
        // copy first node
        topPtr = new WordNode;
        topPtr->item = aStack.topPtr->item;

        // copy rest of stack
        WordNode *newPtr = topPtr;
        for (WordNode *origPtr = aStack.topPtr->next;
             origPtr != NULL;
             origPtr = origPtr->next) {
            newPtr->next = new WordNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}// destructor
Stack::~Stack() {

    // pop until stack is empty
    while (!isEmpty())
        pop();

}
bool Stack::isEmpty() const {

    return topPtr == NULL;

}
bool Stack::push(Word newItem) {

    // create a new node
    WordNode *newPtr = new WordNode;

    // set data portion  of new node
    newPtr->item = newItem;

    // insert the new node
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}
bool Stack::pop() {

    if (isEmpty())
        return false;

        // stack is not empty; delete top
    else{
        WordNode *temp = topPtr;
        topPtr = topPtr->next;

        // return deleted node to system
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }
}
bool Stack::pop(Word& stackTop) {

    if (isEmpty())
        return false;

        // not empty; retrieve and delete top
    else{
        stackTop = topPtr->item;
        WordNode *temp = topPtr;
        topPtr = topPtr->next;

        // return deleted node to system
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }
}
bool Stack::getTop(Word& stackTop)
const {

    if (isEmpty())
        return false;

        // stack is not empty; retrieve top
    else {
        stackTop = topPtr->item;
        return true;
    }

}