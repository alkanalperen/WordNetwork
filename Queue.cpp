//
// Created by Alperen Alkan on 10.05.2021.
//
/**
* Title: Balanced Search Trees, Hashing and Graphs * Author: Name Surname
* ID: 21803216
* Section: 3
* Assignment: 4
 * alperen alkan
*/
#include "Queue.h"
Queue::Queue() : backPtr(NULL), frontPtr(NULL){

}



// copy constructor
Queue::Queue(const Queue& Q){

    // Implementation left as an exercise (Exercise 4)

}
Queue::~Queue(){

    while (!isEmpty())
        dequeue();

}
bool Queue::isEmpty() const {

    return backPtr == NULL;

}
bool Queue::enqueue(Word newItem){

    // create a new node
    WordNode *newPtr = new WordNode;

    // set data portion of new node
    newPtr->item = newItem;
    newPtr->next = NULL;

    // insert the new node
    if (isEmpty())   // insertion into empty queue
        frontPtr = newPtr;
    else             // insertion into nonempty queue
        backPtr->next = newPtr;

    backPtr = newPtr;  // new node is at back

    return true;
}
bool Queue::dequeue(){

    if (isEmpty())
        return false;

    else{
        // queue is not empty; remove front
        WordNode *tempPtr = frontPtr;

        if (frontPtr == backPtr){   // special case
            frontPtr = NULL;
            backPtr = NULL;
        }
        else
            frontPtr = frontPtr->next;

        tempPtr->next = NULL;  // defensive strategy
        delete tempPtr;
        return true;
    }
}
bool Queue::dequeue(Word& queueFront){

    if (isEmpty())
        return false;

    else{
        // queue is not empty; retrieve front
        queueFront = frontPtr->item;
        dequeue();  // delete front

        return true;
    }

}
bool Queue::getFront(Word& queueFront)const {

    if (isEmpty())
        return false;

    else {
        // queue is not empty; retrieve front
        queueFront = frontPtr->item;

        return true;
    }

}