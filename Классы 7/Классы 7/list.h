#pragma once
#include <iostream>
using namespace std;

#ifndef LIST_H 
#define LIST_H 

template <typename T>
class List;

template <typename T>
struct Node {
	Node<T>* prev = nullptr, * next = nullptr;
	T data;
};

template <typename T>
class Iterator {
	template <typename T>
	friend class List;
	Node<T>* elem;
public:
	Iterator() { elem = nullptr; }
	Iterator(const Iterator<T>& it) { elem = it.elem; }
	Iterator<T>& operator=(const Iterator<T>& a) {
		elem = a.elem;
		return *this;
	}
	bool operator==(const Iterator<T>& it) { return elem == it.elem; }
	bool operator!=(const Iterator<T>& it) { return elem != it.elem; };
	Iterator<T>& operator++() {
		elem = elem->next;
		return *this;
	};
	Iterator<T>& operator--() {
		elem = elem->prev;
		return *this;
	}
	Iterator<T>& operator+(const int& a) {
		for (int i = 0; i < a; i++) elem = elem->next;
		return *this;
	}
	Iterator<T>& operator-(const int& a) {
		for (int i = 0; i < a; i++) elem = elem->prev;
		return *this;
	}
	T& operator *() const { return elem->data; }

};

template <typename T>
class List {
private:
	int size;
	Node<T>* head = nullptr, * tail = nullptr;
	Iterator<T> beg, end;
public:
	List();
	List(int s, T k);
	List(const List<T>&);
	~List();
	T front();
	T back();
	void pushback(T data);
	void pushfront(T data);
	void popback();
	void popfront();
	bool empty();
	List<T>& operator=(const List<T>&);
	T& operator[](int index);
	int& operator()();
	List<T> operator*(List<T>&);
	friend ostream& operator << <T>(ostream&, const List<T>&);
	friend istream& operator >> <T>(istream&, const List<T>&);
	Iterator<T> first() { return beg; }
	Iterator<T> last() { return end; }
};

template <typename T>
List<T>::List(int s, T k) {
	size = s;
	Node<T>* node = new Node<T>;
	node->data = k;
	head = node;
	tail = node;
	for (int i = 0; i < size - 1; i++) {
		Node<T>* node = new Node<T>;
		node->data = k;
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	tail->next = nullptr;
	beg.elem = head;
	end.elem = tail->next;
}
template <typename T>
List<T>::List() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template <typename T>
List<T>::List(const List<T>& a) {
	Node<T>* node = a.head;
	while (node != nullptr) {
		pushback(node->data);
		node = node->next;
	}
	beg = a.beg;
	end = a.end;
}
template <typename T>
List<T>::~List() {
	Node<T>* curr = head;
	while (curr != nullptr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
}
template <typename T>
void List<T>::pushback(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		size++;
		end.elem = tail->next;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		size++;
		end.elem = tail->next;
	}
}
template <typename T>
void List<T>::pushfront(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		size++;
		beg.elem = head;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		size++;
		beg.elem = head;
	}
}
template <typename T>
T List<T>::front() { return head->data; }
template <typename T>
T List<T>::back() { return tail->data; }
template <typename T>
void List<T>::popback() {
	if (head != nullptr) {
		Node<T>* curr = tail;
		tail = curr->prev;
		delete curr;
		tail->next = nullptr;
		size--;
		end.elem = tail->next;
	}
}
template <typename T>
void List<T>::popfront() {
	if (head != nullptr) {
		Node<T>* curr = head;
		head = curr->next;
		delete curr;
		head->prev = nullptr;
		size--;
		beg.elem = head;
	}
}
template <typename T>
bool List<T>::empty() { return size == 0; }

template <typename T>
List<T>& List<T>::operator=(const List<T>& a) {
	if (this == &a) return *this;
	Node<T>* node = head;
	while (node != nullptr) {
		head = node->next;
		delete node;
		node = head;
		size--;
	}
	Node<T>* curr = a.head;
	while (curr != nullptr) {
		pushback(curr->data);
		curr = curr->next;
	}
	beg = a.beg;
	end = a.end;
	return *this;
}
template <typename T>
T& List<T>::operator[](int index) {
	if (index < size && index >= 0) {
		Node<T>* curr = head;
		for (int i = 0; i < index; i++) curr = curr->next;
		return curr->data;
	}
	else {
		cout << "Wrong index!" << endl;
		exit(222);
	}

}
template <typename T>
int& List<T>::operator ()() {
	return size;
}
template <typename T>
List<T> List<T>::operator*(List<T>& a) {
	int tempsize;
	if (size > a.size) tempsize = a.size;
	else tempsize = size;
	List<T> templist(tempsize, a[0]);
	for (int i = 0; i < tempsize; i++) templist[i] = (*this)[i] * a[i];
	return templist;

}

template <typename T>
ostream& operator<<(ostream& out, const List<T>& a) {
	Node<T>* curr = a.head;
	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
	return out;
}
template <typename T>
istream& operator>>(istream& in, const List<T>& a) {
	Node<T>* curr = a.head;
	while (curr != nullptr) {
		in >> curr->data;
		curr = curr->next;
	}
	return in;
}

#endif LIST_H
