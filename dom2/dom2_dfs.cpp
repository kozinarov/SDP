// dom2_dfs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "DynamicArray.h"
#include <stack>


using namespace std;


template<typename T>
struct Coord
{
	T x;
	T y;
};


DynamicArray<Coord<int> > allNodes;


//finding all reachable points
void BFS(char **matrix, int N, int M, Coord<int> cstart)
{	
	Queue<Coord<int> > q;
	bool** visited = new bool*[N];
	for (int i = 0; i < N; ++i)
		visited[i] = new bool[M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = false;


	q.push(cstart);
	while (!q.empty())
	{
		int x = q.top().x;
		int y = q.top().y;
	
		visited[x][y] = true;
		q.pop();
		Coord<int> tmp;
		
		
		if (x + 1 < N && matrix[x + 1][y] == '.' && !visited[x + 1][y])
		{
			visited[x + 1][y] = true;
			tmp.x = x + 1;
			tmp.y = y;
			q.push(tmp);
			allNodes.add(tmp);
			cout << "(" << x + 1 << ", " << y << ")";

		}

		if (y + 1 < M && matrix[x][y + 1] == '.' && !visited[x][y + 1])
		{
			visited[x][y + 1] = true;
			tmp.x = x;
			tmp.y = y + 1;
			q.push(tmp);
			allNodes.add(tmp);
			cout << "(" << x << ", " << y + 1 << ")";

		}

		if (y - 1 >= 0 && matrix[x][y - 1] == '.' && !visited[x][y - 1])
		{
			visited[x][y - 1] = true;
			tmp.x = x;
			tmp.y = y - 1;
			allNodes.add(tmp);
			q.push(tmp);
		
			cout << "(" << x << ", " << y - 1 << ")";
			 
		}

		if (x - 1 >= 0 && matrix[x - 1][y] == '.' && !visited[x - 1][y])
		{
			visited[x - 1][y] = true;
			tmp.x = x - 1;
			tmp.y = y;
			allNodes.add(tmp);
			q.push(tmp);
		
			cout << "(" << x - 1 << ", " << y << ")";

		}
	}
	cout << endl << endl;
}


//finding the paths 
void DFS(char **matrix, int N, int M, Coord<int> cStart, Coord<int> cEnd)
{
	stack<Coord<int> > s;
	stack<Coord<int> > tmpS;
	Coord<int> tmpC;

	bool** visited = new bool*[N];
	for (int i = 0; i < N; ++i)
		visited[i] = new bool[M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = false;

	bool cntToPrint = 0;

	s.push(cStart);

	while (!s.empty())
	{

		int x = s.top().x;
		int y = s.top().y;
		Coord<int> tmp;

		if (x == cEnd.x && y == cEnd.y)
		{
			while (!s.empty())
			{
				tmpC.x = s.top().x;
				tmpC.y = s.top().y;
				tmpS.push(tmpC);
				s.pop();
			}
			while (!tmpS.empty())
			{
				cout << "(" << tmpS.top().x << ", " << tmpS.top().y << ")";
				tmpC.x = tmpS.top().x;
				tmpC.y = tmpS.top().y;
				s.push(tmpC);
				tmpS.pop();
			}
			s.pop();
			cout << endl;
		}
		
		visited[x][y] = true;

		
		if (x + 1 < N && matrix[x + 1][y] == '.' && !visited[x + 1][y])
		{
			
			visited[x + 1][y] = true;
			tmp.x = x + 1;
			tmp.y = y;
			s.push(tmp);

		}
		else if (y + 1 < M && matrix[x][y + 1] == '.' && !visited[x][y + 1])
		{
			
			visited[x][y + 1] = true;
			tmp.x = x;
			tmp.y = y + 1;
			s.push(tmp);

		}
		else if (y - 1 >= 0 && matrix[x][y - 1] == '.' && !visited[x][y - 1])
		{
			
			visited[x][y - 1] = true;
			tmp.x = x;
			tmp.y = y - 1;
			s.push(tmp);

		}
		else if (x - 1 >= 0 && matrix[x - 1][y] == '.' && !visited[x - 1][y])
		{
			
			visited[x - 1][y] = true;
			tmp.x = x - 1;
			tmp.y = y;
			s.push(tmp);


		}
		else
		{
			s.pop();
		}

	}
}



int main()
{
	Coord<int> cstart;
	Coord<int> tmpEnd;
	int N, M;
	cout << "N: ";
	cin >> N;
	cout << "M: ";
	cin >> M;

	char** matrix = new char*[N];
	for (int i = 0; i < N; ++i)
		matrix[i] = new char[M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> matrix[i][j];

	cout << "start ";
	cin >> cstart.x;
	cin >> cstart.y;

	if (cstart.x > N || cstart.x < 0)
		cout << "Bad start poin";
	if (cstart.y > M || cstart.y < 0)
		cout << "Bad start poin";
	

	BFS(matrix, N, M, cstart);


	int size = allNodes.size();
	for (int i = 0; i < size; i++)
	{
		cout << "(" << allNodes.get(i).x << ", " << allNodes.get(i).y << ")" << endl;
		tmpEnd.x = allNodes.get(i).x;
		tmpEnd.y = allNodes.get(i).y;

		DFS(matrix, N, M, cstart, tmpEnd);
		cout << endl;
	}
	
    return 0;
}

