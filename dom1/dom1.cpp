// dom1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Stack.h"
#include "DinamicArray.h"
#include <string>
#include <stack>



using namespace std;
int main()
{	
	Stack<char> _Stack;
	DynamicArray<char> letters;
	DynamicArray<char> templetters;

	string string;
	cout << "Enter string: ";
	getline(cin, string);
	
	char top;
	char lasttop;
	
	for (int i = 0; i < string.length(); i++)
	{	
		
		_Stack.push(string[i]);
	}
	
	

	int cntlasttop = 0;
	
	while (_Stack.head())											
	{	
		top = _Stack.head();
		//searching for ) and deleting it
		if (top == ')')
		{
			_Stack.pop();
			//Filling the final string with the temp )
			for (int j = 0; j < templetters.size(); j++)
			{
				letters.insertAtBeggining(templetters.get(j));
			}
			templetters.Free();
			
			
			
		}
		//searching for letters		
		if(top >= 'A' && top <= 'Z')
		{	
			
			templetters.add(top);
			_Stack.pop();
			
		}

     		//searching for ( and deleting it
		if (top == '(')
		{
			_Stack.pop();
			
			if (lasttop >= '0' && lasttop <= '9')
			{
				cntlasttop = 1;
			}
			else
			{
				cntlasttop = 0;
			}
			
		}
	

		//searching for the existance of letters
		if (top >= '0' && top <= '9')
		{	
			
				//this is when i have ) and after that letter
				if (cntlasttop == 1)
				{
	
					for (int j = 0; j < templetters.size(); j++)
					{
						letters.insertAtBeggining(templetters.get(j));
					}
					int convchar = top - '0';
					letters.copy(convchar);
					templetters.Free();
				}
				else
				{
					//this is when i have ( and after that letter
					int convchar = top - '0';
					templetters.copy(convchar);

				
				}
			
			_Stack.pop();
		
		}
			lasttop = top;
		
	}

	for (int j = 0; j < templetters.size(); j++)
	{
		letters.insertAtBeggining(templetters.get(j)); 
	}

	for (int i = 0; i < letters.size(); i++)
	{

		cout << letters.get(i);
	}
	cout << endl;

	

    return 0;
}

