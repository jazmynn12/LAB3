#include "currency.cpp"
#include "DoublyLinkedList.cpp"
#pragma once
class LLQueue : private DoublyLinkedList {
public:
    LLQueue() : DoublyLinkedList() {}
    ~LLQueue() {}; 

    void enqueue( Currency * currency) {
        addCurrency(currency);
    }

    Currency * dequeue() {
        return removeCurrency(0);
    }

    Currency * peekFront() {
        return getCurrency(0);
    }

    Currency * peekRear() {
        return getEnd()->getData();
    }

    std::string toString() {
        return printList();
    }

};
