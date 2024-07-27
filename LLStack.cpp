/** 
 * Lab Number: 3
 * Name: Mira Haldar and Jazmyne Newman
 * This program will edit a stack depending on a given task*/

#include "currency.cpp"
#include "DoublyLinkedList.cpp"
#pragma once
class LLStack : private DoublyLinkedList {
public:
    LLStack() : DoublyLinkedList() {}
/*post : empty stack is created*/
    ~LLStack() {}; 
/*post : stack is destroyed and memory is released*/
    void push( Currency * currency) {
/*pre : a valid currency object is provided
post : object is added to top of stack*/
        addCurrency(currency, 0);
    }
/*pre : stack is not empty
post : object at top of stack is removed and returned*/
    Currency * pop() {
        return removeCurrency(0);
    }
/*pre : stack is not empty
post : object at top of stack is returned without removal*/
    Currency * peek() {
        return getCurrency(0);
    }
/*post : a string representation of the stack's contents is returned*/
    std::string toString() {
        return printList();
    }
};
