#pragma once



using namespace std;
template <class T>
class Stack {
	class node {
	public:
		T data;
		node* next;

		node(T const &d) : data(d), next(0) {}

	
		node() : data(NULL), next(NULL) {}
	};
	
	node *head;

public:
	Stack() : head(0) {}

	~Stack() {
		if (head) {
			node* current = head;
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
		n->next = head;
		head = n;
	}
	void pop()
	{
		node *n = head;
		head = head->next;
		n->next = NULL;
		delete n;
	}
	T top()
	{
		if (head)
		{
			node *n = head;
			return n->data;
		}
		

	}
	bool empty()
	{
		if (!head)
			return NULL;
	}

};


