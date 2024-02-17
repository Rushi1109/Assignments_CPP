
#include "./include/LinkedList.h"

int main(){
    LinkedList<int> l1{ {23, 45, 45} };
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
    l1.insertAtIndex(1u, 15);
    l1.insertAtIndex(1u, 15);
    l1.insertAtIndex(1u, 15);
    l1.insertAtIndex(1u, 15);
    l1.insertAtIndex(6u, 20);
    l1.insertAtIndex(23u, 23);
    l1.deleteAtIndex(5u);
    l1.display();

    LinkedList<std::string> ls{ "abc00", "asc", "wed" };
    ls.display();

    LinkedList<char> lc{ 'a', 'v', 'n'};
    lc.display();

    LinkedList<float> lf{ 3.9f, 2.3f, 4.5f };
    lf.display();
}