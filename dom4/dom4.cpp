// dom4 trie tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"
#include <iostream>

using namespace std;

int main()
{
	string s1, s2;
	Tree* tree1 = new Tree();
	Tree* tree2 = new Tree();
	getline(cin, s1);
	getline(cin, s2);

	tree1->fill(s1);
	tree2->fill(s2);

}