#include "../include/LinkedList.h"
#include<iostream>
LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::LinkedList(const std::initializer_list<int>& list) {
	for (auto& val : list) {
		insertAtTail(val);
	}
}

void LinkedList::display() const {
	if (head == nullptr) {
		std::cout << "List is empty" << '\n';
		return;
	}

	auto temp = head;
	
	while (temp) {
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}
	std::cout << "null\n";
}

int LinkedList::length() const {
	if (!head) {
		return 0;
	}

	auto size = 1;
	auto temp = head;
	while (temp->next) {
		size++;
		temp = temp->next;
	}

	return size;
}

void LinkedList::insertAtHead(int val) {
	if (head == nullptr) {
		head = std::make_shared<Node>(val);
		return;
	}
	auto tempHead = std::make_shared<Node>(val);
	tempHead->next = head;
	head = tempHead;
}

void LinkedList::insertAtTail(int val) {
	if (head == nullptr) {
		insertAtHead(val);
		return;
	}

	auto temp = head;
	
	while (temp->next) {
		temp = temp->next;
	}

	temp->next = std::make_shared<Node>(val);
}

void LinkedList::insertAtIndex(int index, int val) {
	if (index == 0) {
		insertAtHead(val);
		return;
	}

	if (index > length()-1) {
		std::cout << "Index larger than size" << '\n';
		return;
	}

	auto temp = head;
	while (index-1 > 0) {
		temp = temp->next;
		index--;
	}

	auto newNode = std::make_shared<Node>(val);
	newNode->next = temp->next;
	temp->next = newNode;
}

void LinkedList::deleteAtHead() {
	if (!head) {
		std::cout << "List is empty" << '\n';
		return;
	}

	head = head->next;
}

void LinkedList::deleteAtTail() {
	if (!head) {
		return;
	}

	auto curr = head;
	auto prev = curr;

	while (curr->next) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = nullptr;
}

void LinkedList::deleteAtIndex(int index) {
	if (!head) {
		return;
	}

	if (index > length() - 1) {
		std::cout << "Index larger than size" << '\n';
		return;
	}

	auto temp = head;
	while (index - 1 > 0) {
		temp = temp->next;
		index--;
	}

	temp->next = temp->next->next;
}