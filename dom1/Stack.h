#pragma once


using namespace std;
template <class T>
class Stack {
	class node {
	public:
		T data;
		node* next;

		node(T const &d) : data(d), next(0) {}

		node() : data(0), next(0) {}
	};

	node *top;

public:
	Stack() : top(0) {}
	
	~Stack() {
		if (top) {
			node* current = top;
			node* next = 0;
			while (current != 0) {
				next = current->next;
				delete current;
				current = next;
			}
		}
	}

	void push(const T& item)
	{
		node *n = new node;
		n->data = item;
		n->next = top;
		top = n;
	}
	void pop()
	{
		node *n = top;
		top = top->next;
		n->next = NULL;
		delete n;
	}
	T head()
	{
		if (top)
		{
			node *n = top;
			return n->data;
		}
		return NULL;

	}

};


