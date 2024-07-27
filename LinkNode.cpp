/**
*Lab Number: 3
*Name: Mira Haldar and Jazmyne Newman
* This program will hold a pointer to an instance of the Currency class, point to the next and previous node in the doubly linked list 
*/

#include "currency.cpp"
#pragma once

/** pre : data - holds pointer to an instance of the Currency class
*         next : points to next node in the list
*         prev : points to previous node in the list
*/
class LinkNode {
private:
    Currency * data;
    LinkNode* next;
    LinkNode* prev;

public:
    LinkNode(Currency * d) {
       // std::cout << d->toString(); 
        data = d; 
        //std::cout << data->toString(); 
         next = nullptr; 
         prev = nullptr; 
       
    }

    Currency* getData() {
        return data;
    }
    // void setData(Currency c) {
    //     data = c;
    // }
    LinkNode* getNext() {
        return next;
    }

    void setNext(LinkNode* n) {
        next = n;
    }

    LinkNode* getPrev() {
        return prev;
    }

    void setPrev(LinkNode* p) {
        prev = p;
    }
};
 /* post : used in conjuction w/ DoubleLinkedList class to manage collection on LinkNode objects
*/
