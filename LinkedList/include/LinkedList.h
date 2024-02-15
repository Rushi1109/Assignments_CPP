#ifndef _LinkedList_h_
#define _LinkedList_h_

#include<memory>

class LinkedList;

struct Node {
private:
	int data;
	std::shared_ptr<Node> next;
public:
	Node() : data{ 0 }, next{ nullptr } {}
	Node(int val) : data{ val }, next{ nullptr } {}

	friend class LinkedList;
};

class LinkedList {
private:
	std::shared_ptr<Node> head = { nullptr };
	
public:
	LinkedList();
	LinkedList(const std::initializer_list<int>&);

	void display() const;

	int length() const;

	void insertAtHead(int val);
	void insertAtTail(int val);
	void insertAtIndex(int index, int val);

	void deleteAtHead();
	void deleteAtTail();
	void deleteAtIndex(int index);
};





#endif 
