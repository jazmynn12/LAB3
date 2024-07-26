#include "currency.cpp"
#include "LinkNode.cpp"
#pragma once 
class DoublyLinkedList {
private:
    int count;
    LinkNode* start;
    LinkNode* end;

public:
    DoublyLinkedList() : count(0), start(nullptr), end(nullptr) {}

    ~DoublyLinkedList() {
        while (start != nullptr) {
            LinkNode* temp = start;
            start = start->getNext();
            delete temp;
        }
    }

    void addCurrency(Currency * curr, int index) {
        if (index < 0 || index > count) {
            throw std::out_of_range("Index out of range");
        }
        LinkNode* newNode = new LinkNode(curr);
        if (index == 0) {
            newNode->setNext(start); 
            if (start != nullptr) {
                start->setPrev(newNode); 
                
            }
            start = newNode; 
            if (end == nullptr) {
                end = newNode;
            }
        } else if (index == count) {
            newNode->setPrev( end);
            if (end != nullptr) {
                end->setNext( newNode);
            }
            end = newNode;
        } else {
            LinkNode* current = start;
            for (int i = 0; i < index - 1; ++i) {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            newNode->setPrev(current);
            current->getNext()->setPrev( newNode);
            current->setNext(newNode);
        }
        ++count;
    }
    void addCurrency(Currency * curr) { 
       // std:: cout << "THIS METHOD IS IN USE\n"; 
        LinkNode* newNode = new LinkNode(curr);
        if(start==nullptr){ 
            start = newNode; 
        }
        newNode->setPrev( end);
        if (end != nullptr) {
            end->setNext( newNode);
        }
        end = newNode;
        count++; 
    }
    Currency * removeCurrency(Currency * currency) {
        LinkNode* current = start;
        while (current != nullptr) {
            if (current->getData()->isEqual(*currency)) {
                if (current->getPrev() != nullptr) {
                    current->getPrev()->setNext(current->getNext());
                } else {
                    start = current->getNext();
                }
                if (current->getNext() != nullptr) {
                    current->getNext()->setPrev( current->getPrev());
                } else {
                    end = current->getPrev();
                }
                Currency * removedCurrency = current->getData();
                delete current;
                --count;
                return removedCurrency;
            }
            current = current->getNext();
        }
        throw std::invalid_argument("Currency not found");
    }

    Currency * removeCurrency(int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }
        LinkNode* current = start;
        for (int i = 0; i < index; ++i) {
            current = current->getNext();
        }
        if (current->getPrev() != nullptr) {
            current->getPrev()->setNext(current->getNext());
        } else {
            start = current->getNext();
        }
        if (current->getNext() != nullptr) {
            current->getNext()->setPrev(current->getPrev());
        } else {
            end = current->getPrev();
        }
        Currency * removedCurrency = current->getData();
        delete current;
        --count;
        return removedCurrency;
    }

    int findCurrency(Currency * currency) {
        LinkNode* current = start;
        int index = 0;
        while (current != nullptr) {
            if (current->getData()->isEqual(*currency)) {
                return index;
            }
            current = current->getNext();
            ++index;
        }
        return -1; // Currency not found
    }

    Currency * getCurrency(int index) {
        std::cout <<index << " METHOD IN USE: \n"; 
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }
        LinkNode* current = start;
        for (int i = 0; i < index; ++i) {
            current = current->getNext();
        }
        return current->getData();
    }
    LinkNode * getEnd() { 
        return end; 
    }
    std::string printList() {
        std::string list;
        LinkNode* current = start;
        while (current != nullptr) {
            list += current->getData()->toString() + "\t";
            current = current->getNext();
        }
        return list;
    }
    int getCount(){ 
        LinkNode * h = start; 
        int length = 0; 
        while (h != nullptr){ 
            h = h->getNext(); 
            length++; 
        }
        return length; 
    }
};
