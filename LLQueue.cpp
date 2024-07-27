/** 
 * Lab Number: 3
 * Name: Mira Haldar and Jazmyne Newman
 This program will edit the list depending on the task
*/

#include "currency.cpp"
#include "DoublyLinkedList.cpp"
#pragma once
class LLQueue : private DoublyLinkedList {
public:
    LLQueue() : DoublyLinkedList() {}
/*post : empty queue is created*/
    ~LLQueue() {}; 
/*post : queue is destroyed and memory is released */

/*pre : a valid Currency object is provided
 *post : add object to end of queue 
*/

    void enqueue( Currency * currency) {
        addCurrency(currency);
    }
/* post : remove and returns object from front of queue*/
    Currency * dequeue() {
        return removeCurrency(0);
    }
/*  pre : queue not empty
    post : returns copy of 1st node in queue*/
    Currency * peekFront() {
        return getCurrency(0);
    }
/*  pre : queue not empty
    post : returns copy of last node in queue*/
    Currency * peekRear() {
        return getEnd()->getData();
    }
/*post : a string representsation of the queue's content is returned*/
    std::string toString() {
        return printList();
    }

};
