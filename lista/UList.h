#pragma once
#include "Node.h"
#include <iostream>

template <class T>
class TList {
private:
	int length;
	Node<T>* head;
	Node<T>* tail;
public:
	TList();
	~TList();
	void push_front(T data);
	void push_back(T data);
	void pop_back();
	void print();
	int getLength();
	T getFirst();
	T getLast();
	T* begin();
	bool empty();
};

//List class
template<class T>
TList<T>::~TList() {
	std::cout << "\nZniszczono liste\n\n";
}

template<class T>
TList<T>::TList() {
	this->length = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

template<class T>
void TList<T>::push_front(T data) {
	Node<T>* node = new Node<T>(data);
	node->setData(data);
	node->setNext(this->head);
	this->head = node;
	if (length == 0) {
		tail = head;
	}
	this->length++;
}

template<class T>
void TList<T>::print() {
	Node<T>* head_now = this->head;
	int i = 1;
	while (head_now) {
		std::cout << i << " : " << head_now->getData() << std::endl;
		head_now = head_now->getNext();
		i++;
	}
}

template <class T>
int TList<T>::getLength() {
	return length;
}

template <class T>
T TList<T>::getFirst() {
	return head->getData();
}

template <class T>
T TList<T>::getLast() {
	Node<T>* head_now = this->head;
	int i = 0;
	while (i < this->length-1) {
		head_now = head_now->getNext();
		i++;
	}
	return head_now->getData();
}

template<class T> 
T* TList<T>::begin() {
	T* ptr = &head->getData();
	return ptr;
}

template<class T>
void TList<T>::pop_back() {

}

template <class T>
void TList<T>::push_back(T data) {
	if (length == 0) {
		push_front(data);
	}
	else {
		Node<T>* node = new Node<T>(data);
		node->setNext(tail->getNext());
		this->tail->setNext(node);
		this->tail = node;
		length++;
	}
}

template <class T>
bool TList<T>::empty() {
	if (length == 0) {
		return true; //is empty
	}
	else {
		return false; //is not empty
	}
}