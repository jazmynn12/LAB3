#include "currency.cpp"
#include "DoublyLinkedList.cpp"
#pragma once
class LLStack : private DoublyLinkedList {
public:
    LLStack() : DoublyLinkedList() {}
    ~LLStack() {}; 
    void push( Currency * currency) {
        addCurrency(currency, 0);
    }

    Currency * pop() {
        return removeCurrency(0);
    }

    Currency * peek() {
        return getCurrency(0);
    }

    std::string toString() {
        return printList();
    }
};
