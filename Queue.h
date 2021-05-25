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
#ifndef INC_21803216_HW4_QUEUE_H
#define INC_21803216_HW4_QUEUE_H


#include "Word.h"

class Queue {
public:
    Queue();                     // default constructor
    Queue(const Queue& Q);       // copy constructor
    ~Queue();                    // destructor

    // Queue operations:
    bool isEmpty() const;
    bool enqueue(Word newItem);
    bool dequeue();
    bool dequeue(Word& queueFront);
    bool getFront(Word& queueFront) const;

private:
    // The queue is implemented as a linked list with one external
    // pointer to the front of the queue and a second external
    // pointer to the back of the queue.

    struct WordNode{
        Word  item;
        WordNode     *next;
    };
    WordNode *backPtr;
    WordNode *frontPtr;

};


#endif //INC_21803216_HW4_QUEUE_H
