/*Lab Number: 3
 *Name: Mira Haldar and Jazmyne Newman
* This program will uses the LinkNode and Currency class to present list
*/

#include "currency.cpp"
#include "LinkNode.cpp"
#pragma once 

class DoublyLinkedList {
private:

/*pre : count - keeps track of number of nodes in the list, start - a pointer to the first node and 
end - a point to the last node in the list*/

    int count;
    LinkNode* start;
    LinkNode* end;

public:
    DoublyLinkedList() : count(0), start(nullptr), end(nullptr) {}

/*post : initializes an empty list with the count set to 0, start and end set to nullptr
*/
    ~DoublyLinkedList() {
        while (start != nullptr) {
            LinkNode* temp = start;
            start = start->getNext();
            delete temp;
        } 
        /*post : deallocates all node in the ~DoublyLinkedList
        */
    }
/*pre : currency object and valid index
*/

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
/*post : adds the currency onject to the list at a specific index
*/
    void addCurrency(Currency * curr) { //adds new Linknode object automatically to the end of the list 
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
/*pre : currency object exists in the list
*/
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
/*pre : valid index (0 <= index < count)
*/
/*post : removes currency object at a specific index and returns a copy
*/
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
/*pre : currency object exists in list
*/
/*post : returns the index of the specific Currency object in the list, or -1 if not found
*/
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
/*pre : valid index (0 <= index < count)
*/
/*post : returns Currency object at specific index
*/
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

/*post : returns a string of all Currency objects in list, tab spaced
*/

    std::string printList() {
        std::string list;
        LinkNode* current = start;
        while (current != nullptr) {
            list += current->getData()->toString() + "\t";
            current = current->getNext();
        }
        return list;
    }

/*post : returns number of nodesbin the list*/
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
