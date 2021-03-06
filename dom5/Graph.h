#pragma once
#include "vector"
#include "DynamicArray.h"
#include "string"
class Graph {
private:
	int** adjacencyMatrix;
	int N, M;
	

public:
	Graph(int N, int M) {
		this->N = N;
		this->M = M;
		adjacencyMatrix = new int*[N];
		for (int i = 0; i < N; i++) {
			adjacencyMatrix[i] = new int[M];
			for (int j = 0; j < M; j++)
				adjacencyMatrix[i][j] = false;
		}
	}
	Graph operator=(Graph const & other)
	{
		if (this != &other)
		{
			

			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					adjacencyMatrix[i][j] = other.adjacencyMatrix[i][j];
		}

		return *this;
	}
	
	void addEdge(int i, int j) {
		if (i >= 0 && i < N && j >= 0 && j < M) {
			adjacencyMatrix[i][j] = true;
			//adjacencyMatrix[j][i] = true;
		}
	}

	void removeEdge(int i, int j) {
		if (i >= 0 && i < N && j > 0 && j < M) {
			adjacencyMatrix[i][j] = false;
		//	adjacencyMatrix[j][i] = false;
		}
	}

	int isEdge(int i, int j) {
		if (i >= 0 && i < N && j >= 0 && j < M)
			return adjacencyMatrix[i][j];
		
	}


	//fill array whith indexes 
	void maxConections(DynamicArray<int>& v)
	{	
		
		int sum = 0, final_sum = 0;
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				sum += adjacencyMatrix[i][j];
			}
			if (sum > final_sum)
			{
				v.Free();
				v.add(i);
				final_sum = sum;
			}
			else if (sum == final_sum)
			{
				v.add(i);
			}
			sum = 0;
		}

	}

	void algoFloydWarshall()
	{
		for (int k = 0; k < N; ++k)
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
				{
					if (adjacencyMatrix[i][j] > adjacencyMatrix[i][k] + adjacencyMatrix[k][j])
						adjacencyMatrix[i][j] = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
				}
	}
	
	void closenessCentrality(DynamicArray<int>& v)
	{
		int num = 0, final_num = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				num = adjacencyMatrix[i][j];
			}
			if (num > final_num)
			{
				v.Free();
				v.add(i);
				final_num = num;
			}
			else if (num == final_num)
			{
				v.add(i);
			}
			num = 0;
		}
	}

	void change(int i, int j, int value)
	{	
		if (i >= 0 && i < N && j >= 0 && j < M)
			adjacencyMatrix[i][j] = value;
	}

	
	
	~Graph() {
		for (int i = 0; i < N; i++)
			delete[] adjacencyMatrix[i];
		delete[] adjacencyMatrix;
	}
};
