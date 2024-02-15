
#include "./include/LinkedList.h"
#include<iostream>

int main(){
    LinkedList l1{ 23,25,57 };
    l1.display();
    l1.insertAtHead(32);
    l1.insertAtHead(21);
    l1.insertAtTail(35);
    l1.insertAtTail(23);
    l1.insertAtHead(12);
    std::cout << l1.length() << '\n';
    l1.display();
    l1.deleteAtHead();
    l1.display();
    l1.deleteAtTail();
    l1.insertAtIndex(1, 15);
    l1.insertAtIndex(1, 15);
    l1.insertAtIndex(1, 15);
    l1.insertAtIndex(1, 15);
    l1.insertAtIndex(6, 20);
    l1.insertAtIndex(23, 23);
    l1.deleteAtIndex(5);
    l1.display();
}