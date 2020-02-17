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
	class Iterator {
		Node<T>* current_segment;
		
	public:
		Iterator():current_segment(nullptr){}
		~Iterator();
		void operator = (Node<T>* obj);
		T operator * ();
		typename Iterator& operator ++();
		typename Iterator operator ++(int);
		bool operator < (const Iterator& rhs) {
			typename TList<T>::Iterator next;
			next = ++(*this);
			if (current_segment->getNext() == next.current_segment && current_segment->getNext() != rhs.current_segment ) 
			{
				//this < rhs return true
				return false;
			}
			else 
			{
				return true;
			}
		}
		bool operator > (const Iterator& rhs) {
			return (rhs < *this);
		}
		bool operator <= (const Iterator& rhs) {
			return !(*this > rhs);
		}
		bool operator >= (const Iterator& rhs) {
			return !(*this < rhs);
		}
		bool operator == (const Iterator& rhs) {
			if (current_segment == rhs.current_segment) {
				return true;
			}
			else {
				return false;
			}
		}
		bool operator != (const Iterator& rhs) {
			return !(*this == rhs);
		}

	};
	TList();
	~TList();

	void push_front(T data);
	void push_back(T data);
	void pop_back();
	void pop_front();
	void print();

	int size();

	T getFirst();
	T getLast();

	//Are these \/ \/ methods correct? YES
	typename TList<T>::Iterator begin();
	typename TList<T>::Iterator end();

	
	bool empty();

};

//List class
template<class T>
TList<T>::~TList() {
	std::cout << "\n";
}

template<class T>
TList<T>::TList() {
	length = 0;
	head = nullptr;
	tail = nullptr;
}

template<class T>
void TList<T>::push_front(T data) {
	Node<T>* node = new Node<T>(data);
	node->setData(data);
	node->setNext(this->head);
	head = node;
	if (length == 0) {
		tail = head;
	}
	length++;
}

template<class T>
void TList<T>::print() {
	Node<T>* head_now = head;
	int i = 1;
	while (head_now) {
		std::cout << i << " : " << head_now->getData() << std::endl;
		head_now = head_now->getNext();
		i++;
	}
}

template <class T>
int TList<T>::size() {
	return length;
}

template <class T>
T TList<T>::getFirst() {
	return head->getData();
}

template <class T>
T TList<T>::getLast() {
	Node<T>* head_now = head;
	int i = 0;
	while (i < length-1) {
		head_now = head_now->getNext();
		i++;
	}
	return head_now->getData();
}

template<class T>
typename TList<T>::Iterator TList<T>::begin(){
	TList<T>::Iterator it;
	it = head;
	return it;
	//returns iterator to the first element of list
}

template<class T>
typename TList<T>::Iterator TList<T>::end(){
	TList<T>::Iterator it;
	it = tail->getNext();
	return it;
	//returns iterator to the last+1 element of the list
}



template<class T>
void TList<T>::pop_back() {
	//Reconnect remaining list to nullptr

	delete tail;
}

template<class T>
void TList<T>::pop_front() {

}

template <class T>
void TList<T>::push_back(T data) {
	if (length == 0) {
		push_front(data);
	}
	else {
		Node<T>* node = new Node<T>(data);
		node->setNext(tail->getNext());
		tail->setNext(node);
		tail = node;
		length++;
	}
}

template <class T>
bool TList<T>::empty() {
	return length == 0 ? true : false;
}


template<class T>
TList<T>::Iterator::~Iterator()
{
}


//Iterator methods
template <class T>
void TList<T>::Iterator::operator = (Node<T>* obj) {
	current_segment = obj;
}

template<class T>
T TList<T>::Iterator::operator * (){
	return current_segment->getData();
}

template<class T>
typename TList<T>::Iterator& TList<T>::Iterator::operator++()
{
	current_segment = current_segment->getNext();
	return *this;
}

template <class T>
typename TList<T>::Iterator TList<T>::Iterator::operator++(int) {
	typename TList<T>::Iterator it;
	it = this;
	++this;
	return it;
}




//inline bool operator <= (const typename TList<T>::Iterator& lhs, const typename TList<T>::Iterator& rhs) {
//	return !(lhs > rhs);
//}
//

//inline bool operator >= (const typename TList<T>::Iterator& lhs, const typename TList<T>::Iterator& rhs) {
//	return !(lhs < rhs);
//}

