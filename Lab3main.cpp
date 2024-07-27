/** 
 *Lab Number: 
 *Name: Mira Haldar and Jazmyne Newman
 *This file utilizes the LinkNode, DoublyLinkedNode, LLStack and LLQueue file to perform 
 operation
 */

#include "dollar.cpp"
#include "LLQueue.cpp" 
#include "LLStack.cpp" 
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

int main() {
    std::cout << "Demo of the Currency class and ADTs by Mira Haldar and Jazmyne Newman\n\n";

    // Create an array of Currency objects
    Currency * dollarArray[20] = {
        new Dollar( 57.12),
        new Dollar( 23.44),
        new Dollar(87.43),
        new Dollar(68.99),
        new Dollar(111.22),
        new Dollar(44.55),
        new Dollar(77.77),
        new Dollar(18.36),
        new Dollar(543.21),
        new Dollar(20.21),
        new Dollar(345.67),
        new Dollar(36.18),
        new Dollar(48.48),
        new Dollar(101.00),
        new Dollar(11.00),
        new Dollar(21.00),
        new Dollar(51.00),
        new Dollar(1.00),
        new Dollar(251.00),
        new Dollar(151.00)
    };

    // Create DoublyLinkedList, LLStack, and LLQueue objects
    DoublyLinkedList dll;
    LLStack stack;
    LLQueue queue;

    // Perform operations on the linked list
    for (int i = 0; i < 7; ++i) {
       // std::cout << (dollarArray[i])->toString() << "\n ";
        dll.addCurrency(dollarArray[i], 0); // Add to the start to reverse the order
    }
   // std::cout << "Contents of the list after adding first 7 dollars: " << dll.printList() << "\n"; 

    Dollar * cherche = new Dollar(87.43); // Placeholder variable 
    int index = dll.findCurrency(cherche);
    std::cout << "Index of $87.43: " << (index != -1 ? std::to_string(index) : "Not found") << "\n";

    cherche = new Dollar(44.56);
    index = dll.findCurrency(cherche);
    std::cout << "Index of $44.56: " << (index != -1 ? std::to_string(index) : "Not found") << "\n";

    cherche = new Dollar(111.22);  
    dll.removeCurrency(dll.findCurrency(cherche));
    dll.removeCurrency(2);
    std::cout << "Contents of the list: " << dll.printList() << "\n";

    int countCurrency = dll.getCount();
    dll.removeCurrency(countCurrency % 5);
    dll.removeCurrency(countCurrency / 3);
    std::cout << "Contents of the list after additional removals: " << dll.printList() << "\n";

    // Perform operations on the stack
    for (int i = 13; i < 20; ++i) {
        stack.push(dollarArray[i]);
    }


    for (int i = 0; i < 3; ++i) {
        stack.pop();
    }

    for (int i = 0; i < 5; ++i) {
        stack.push(dollarArray[i]);
    }

    for (int i = 0; i < 2; ++i) {
        stack.pop();
    }

    std::cout << "Contents of the stack: " << stack.toString() << "\n";

    // Perform operations on the queue
    for (int i = 5; i < 20; i += 2) {
       // std::cout << "dgfd\n"; 
       
        queue.enqueue(dollarArray[i]);
      //  std::cout << queue.toString() << " : queue \n"; 
    }
    std::cout << queue.toString() << " \n"; 
    std::cout << "Front of the queue: " << queue.peekFront()->toString() << "\n";
    std::cout << "End of the queue: " << queue.peekRear()->toString() << "\n";

    for (int i = 0; i < 2; ++i) {
        
        queue.dequeue();
    }

    for (int i = 10; i < 15; ++i) {
        queue.enqueue(dollarArray[i]);
    }

    for (int i = 0; i < 3; ++i) {
        queue.dequeue();
    }


    std::cout << "Contents of the queue: " << queue.toString() << "\n\n DEMO FINISHED";

    dll.~DoublyLinkedList(); 

    queue.~LLQueue(); 
    stack.~LLStack(); 
    delete dollarArray; 
    std::string quit; 
    std::cout<< "Press a key to quit.." << std::endl; //system pause 
    std::cin >> quit ; 
} 
