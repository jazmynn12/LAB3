#include "currency.cpp"
#pragma once
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

