#pragma once
template<class T>
class Node {
private:
	Node* next;
	T data;
public:
	Node(T data);
	void setNext(Node<T>* next);
	void setData(T data);
	T getData();
	Node* getNext();
	T operator*(Node<T> const& obj) {
		return obj.data;
	}
};

template<class T>
Node<T>::Node(T data) {
	this->data = data;
	this->next = nullptr;
}

template<class T>
void Node<T>::setNext(Node<T>* next) {
	this->next = next;
}

template<class T>
void Node<T>::setData(T data) {
	this->data = data;
}

template<class T>
Node<T>* Node<T>::getNext() {
	return next;
}

template<class T>
T Node<T>::getData() {
	return this->data;
}
