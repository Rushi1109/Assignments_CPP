#ifndef _LinkedList_h_
#define _LinkedList_h_

#include<memory>
#include<iostream>

template<typename T>
class LinkedList;

template<typename U>
struct Node {
private:
	U data;
	std::shared_ptr<Node<U>> next;
public:
	Node() : data{ U{} }, next{ nullptr } {}
	Node(U val) : data{ val }, next{ nullptr } {}

	friend class LinkedList<U>;
};

template<typename T>
class LinkedList {
public:
	LinkedList() {
		head = nullptr;
	}

	LinkedList(const std::initializer_list<T>& list) {
		for (auto& val : list) {
			insertAtTail(val);
		}
	}


	unsigned int length() const {
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


	void display() const {
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


	void insertAtHead(T val) {
		if (head == nullptr) {
			head = std::make_shared<Node<T>>(val);
			return;
		}
		auto tempHead = std::make_shared<Node<T>>(val);
		tempHead->next = head;
		head = tempHead;
	}

	void insertAtTail(T val) {
		if (head == nullptr) {
			insertAtHead(val);
			return;
		}

		auto temp = head;

		while (temp->next) {
			temp = temp->next;
		}

		temp->next = std::make_shared<Node<T>>(val);
	}

	void insertAtIndex(unsigned int index, T val) {
		if (index == 0) {
			insertAtHead(val);
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

		auto newNode = std::make_shared<Node<T>>(val);
		newNode->next = temp->next;
		temp->next = newNode;
	}


	void deleteAtHead() {
		if (!head) {
			std::cout << "List is empty" << '\n';
			return;
		}

		head = head->next;
	}

	void deleteAtTail() {
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

	void deleteAtIndex(int index) {
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

private:
	std::shared_ptr<Node<T>> head = { nullptr };
};





#endif 
