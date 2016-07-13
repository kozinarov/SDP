// dom5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include "DynamicArray.h"
#include "string"
#include "fstream"
#include <assert.h>

using namespace std;
void transpose(Graph & g, Graph & tran_g, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tran_g.change(j, i, g.isEdge(i, j));
		}
	}
}
void multiplicate(Graph & g1, Graph & g2, Graph & final, int N, int M)
{
	int val;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				val = final.isEdge(i, j) + g1.isEdge(i, k) * g2.isEdge(k, j);
				final.change(i, j, val);
			}
		}
	}
}

void split(DynamicArray<string> &v, string line)
{
	string tmp_s;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] != ',')
		{
			tmp_s += line[i];
		}
		else if (tmp_s != "")
		{
			v.add(tmp_s);
			tmp_s.clear();
		}
	}
	v.add(tmp_s);

}
int len(int &N, int &M)
{	

	string line;
	DynamicArray<string> tmp;
	ifstream file;
	file.open("file.csv");
	if (!file.is_open()) {
		cerr << "failed to open file.";
		return 1;
	}
	while (!file.eof())
	{
		file >> line;
		split(tmp, line);
		M = tmp.size()-1;
		tmp.Free();
		N++;
	}
	N = N - 1;
	file.close();
}

int main()
{
	int N = 0;
	int M = 0;
	len(N, M);
	Graph graph(N, M);
	Graph trans_g(M, N);
	Graph people_to_people(N, N);
	Graph group_to_group(M, M);
	DynamicArray<string> people;
	DynamicArray<string> groups;
	DynamicArray<string> tmp;
	DynamicArray<int> iter;
	DynamicArray<int> iter2;
	DynamicArray<int> iter3;
	string line;
	int lineCnt = 0;
	
	ifstream file;
	file.open("file.csv");
	if (!file.is_open()) {
		cerr << "failed to open file.";
		return 1;
	}
	while (!file.eof())
	{
		
		file >> line;
		if (lineCnt == 0)
		{
			split(groups, line);
		}
		else
		{
			split(tmp, line);
			
			people.add(tmp[0]);
			string s;
			
			for (int i = 1; i < tmp.size(); ++i)
			{
				s = tmp[i];
				int val = atoi(s.c_str());
				if (val == 1)
					graph.addEdge(lineCnt-1, i - 1);
			}
			tmp.Free();
	}
		lineCnt++;
	}
	file.close();

	transpose(graph, trans_g, N, M);

	multiplicate(graph, trans_g, people_to_people, N, M);

	people_to_people.maxConections(iter);
	for (int i = 0; i < iter.size(); ++i)
	{
		cout << people[iter[i]] << endl;
	}
	cout << endl;

	multiplicate(graph, trans_g, group_to_group, M, N);
	group_to_group.maxConections(iter2);
	for (int i = 0; i < iter2.size(); ++i)
	{
		cout << groups[iter2[i]] << endl;
	}
	cout << endl;													

	people_to_people.algoFloydWarshall();
	people_to_people.closenessCentrality(iter3);
	for (int i = 0; i < iter3.size(); ++i)
	{
		cout << people[iter3[i]] << endl;
	}
	
	


    return 0;
}

