#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

class Node {
public:
	Node(int val) : Content(val) {}
	~Node() {}

	void setContent(int c) { Content = c; }


	void appendChild(Node* child) { mChildren.push_back(child); }
	int size() { return mChildren.size(); }

private:
	int Content;
	vector<Node*> mChildren;
};

class Tree {
public:
	Tree();
	~Tree();

	int numChild();
	void fill(string s);
private:
	Node* root;
};


Tree::Tree()
{
	root = new Node(NULL);
}

Tree::~Tree() {}


int Tree::numChild()
{
	Node* par = this->root;
	return par->size();
}

void Tree::fill(string s)
{
	string value;
	int v, cnt = 0;
	Node* tmp = new Node(NULL);
	Node* pushNode = new Node(NULL);
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
		{
			cnt++;
			if (cnt % 2 != 0)
			{
				tmp = pushNode;
			}
		}

		if (isdigit(s[i]))
			value.push_back(s[i]);

		if (s[i] == '{')
		{
			v = atoi(value.c_str());
			value.clear();
			pushNode = new Node(v);
			tmp->appendChild(pushNode);


		}
		if (s[i] == ')')
		{
			cnt--;
		}


	}
}