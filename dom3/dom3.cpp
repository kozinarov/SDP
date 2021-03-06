// dom3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include "string"
#include "DynamicArray.h"

using namespace std;
//Radix sort 
void radix_sort_msd(DynamicArray<string> &vect, unsigned int pos)
{
	if (vect.size() <= 1)
	{
		return;
	}

	DynamicArray<string> buck[27];

	for (int i = 0; i < vect.size(); ++i)
	{
		if ((strlen(vect[i].c_str()) - 1) < pos)
		{
			buck[0].push_back(vect[i]);
		}
		else
		{
			buck[((vect[i][pos] - 'a') % 26) + 1].push_back(vect[i]);
		}
	}

	vect.Free();

	for (int i = 0; i<buck[0].size(); ++i)
	{
		vect.push_back(buck[0][i]);
	}

	for (int i = 1; i<27; ++i)
	{
		radix_sort_msd(buck[i], pos + 1);

		for (int j = 0; j < buck[i].size(); ++j)
		{
			vect.push_back(buck[i][j]);
		}
	}

}

//searching for part of name after the sorting
int query(DynamicArray<string> &names, int lo, int hi, string part)
{
	int pos;
	int cnt = 0;
	for (int i = lo; i <= hi; ++i)
	{
		pos = names[i].find(part);
		if (pos == 0)
			cnt++;
	}
	return cnt;
}


void sliceString(DynamicArray<string> &tmpLine, string line)
{

	char * cline = new char[line.length() + 1];
	strcpy_s(cline, line.length() + 1, line.c_str());
	char * p = strtok_s(NULL, " ", &cline);

	while (p != NULL)
	{
		tmpLine.push_back(p);
		p = strtok_s(NULL, " ", &cline);

	}
	delete[] p;

}
int main() 
{

	DynamicArray<string> vect;
	DynamicArray<string> tmpLine;
	DynamicArray<int> outPut;
	string line;

	int num_names, repeats, cases;
	cin >> repeats;
	cin.ignore();
	for (int i = 0; i < repeats; ++i)
	{
	
		getline(cin, line);
		sliceString(tmpLine, line);
		num_names = atoi(tmpLine[0].c_str());
		if (num_names > 1000000 || num_names < 0)
		{
			cout << num_names << "Is bad input";
			return 0;
		}
		cases = atoi(tmpLine[1].c_str());
		if (cases > 500000 || cases < 0)
		{
			cout << "Is bad input";
			return 0;
		}
		tmpLine.Free();

		//reading the line with names
		getline(cin, line);
		sliceString(tmpLine, line);
		if (tmpLine.size() == num_names)
		{
			for (int j = 0; j < num_names; ++j)
			{	
				if (tmpLine[i].size() > 8)
				{
					cout << tmpLine[i] << "Size is bigger then 8" << endl;
					return 0;
				}
				vect.push_back(string(tmpLine[j]));
			}
		}else
		{
			cout << "You have too many names";
			return 0;
		}
		tmpLine.Free();

		

		radix_sort_msd(vect, 0);

		
		cout << endl;
		cout << "Radix sort: ";
		for (int i = 0; i < num_names; ++i)
		{
			cout << vect[i].c_str() << " ";
		}
		cout << endl;


		int lo = 0;
		int hi = vect.size() - 1;
		string choise;

		for (int j = 0; j < cases; ++j)
		{
			getline(cin, line);
			sliceString(tmpLine, line);

			if (tmpLine[0] == "ENTER")
			{
				
				lo = atoi(tmpLine[1].c_str());
				hi = atoi(tmpLine[2].c_str());
				tmpLine.Free();
			}
			else if (tmpLine[0] == "QUERY")
			{
				outPut.push_back(query(vect, lo, hi, tmpLine[1]));
				tmpLine.Free();
			}
			else
			{
				cout << "Incorect command" << endl;
				return 0;
			}
			
		}

	}

	for (int i = 0; i < outPut.size(); ++i)
		cout << outPut[i] << endl;

	return 0;
}

