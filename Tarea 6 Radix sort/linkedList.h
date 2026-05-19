#pragma once

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"
using std::cout;
using std::endl;
using std::runtime_error;


template <typename E>

class linkedList : public List<E> {
private:
	Node<E>* head;
	Node<E>* current;
	Node<E>* tail;
	int size;
public:
	linkedList() {
		head = current = tail = new Node<E>();
		size = 0;
	}
	~linkedList() {
		clear();
		delete head;
	}
	void insert(E element) {
		current->next = new Node<E>(element, current->next);
		if (current == tail)
			tail = tail->next;
		size++;
	}
	void append(E element) {
		tail = tail->next = new Node<E>(element);
		size++;
	}
	void setElement(E element) {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (current == tail)
			throw runtime_error("No current element.");
		current->next->element = element;
	}
	E getElement() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (current == tail)
			throw runtime_error("No current element.");
		return current->next->element;
	}
	E remove() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (current == tail)
			throw runtime_error("No current element.");
		E result = current->next->element;
		Node<E>* temp = current->next;
		current->next = temp->next;
		if (temp == tail)
			tail = current;
		delete temp;
		size--;
		return result;
	}
	void clear() {
		while (head->next != nullptr) {
			current = head->next;
			head->next = current->next;
			delete current;
		}
		size = 0;
		current = tail = head;
		//con for:
		//for (current=head->next;current!=nullptr;current=head->next) despues las lineas de borrado
	}
	void goToStart() {
		current = head;
	}
	void goToEnd() {
		current = tail;
	}
	void goToPos(int pos) {
		if (pos<0 || pos>size)
			throw runtime_error("Invalid Index");
		current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;
	}
	void next() {
		if (current != tail)
			current = current->next;
	}
	void previous() {
		if (current != head) {
			Node<E>* temp = head;
			while (temp->next != current) {
				temp = temp->next;
			}
			current = temp;
		}
	}
	bool atStart() {
		return current == head;
	}
	bool atEnd() {
		return current == tail;
	}
	int getPos() {
		Node<E>* temp = head;
		int pos = 0;
		while (temp != current) {
			temp = temp->next;
			pos++;
		}
		return pos;
	}
	int getSize() {
		return size;
	}
	void print() {
		Node<E>* temp = head;
		int contador = 1;
		while (temp->next != nullptr) {
			cout <<contador << " " << temp->next->element << endl;
			temp = temp->next;
			contador++;
		}
		cout << "]" << endl;
	}
};


