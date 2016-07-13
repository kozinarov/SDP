#include "Memory.h"
#include <iostream>
using namespace std;


Memory::Memory(size_t size)
{
	this->size = size;
	memory = new long long[size/8];
	memory[0] = size/8 - 16;
	memory[size - 1] = memory[0];
}


Memory::~Memory()
{
	this->size = 0;
	delete[] memory;
}

long long* Memory::MyMalloc(size_t Size)
{
	if (Size > this->size)
	{
		std::cout << "Not enough memory";
		return 0;
	}

	if (Size % 8 != 0)
	{
		Size = Size - (Size % 8) + 8;
	}
	int i = 0;

	long long tmp_val = 0;

	//searching for the best spot to get filled
	while(i < this->size)
	{
		if(memory[i] % 8 == 0 && memory[i] < tmp_val && memory[i] >= Size)
		{
			long long last_size = memory[i];
			memory[i] = Size+1;
			i = i + memory[i];
			memory[i] = Size+1;
			memory[i + 1] = last_size - Size;
			memory[i + 1 + (last_size - Size)/8] = memory[i + 1];

		}
		else
		{
			tmp_val = memory[i];
			i = i + memory[i] / 8 + 2;
			
		}
	}
	return &memory[i+1];
}

void Memory::MyFree(long long* pBlock)
{
	int i = pBlock - memory - 1;
	memory[i] = memory[i] - 1;
	memory[i + memory[i] / 8 + 1] = memory[i];

	//in the left is free
	if (i - 1 > 0 && memory[i - 1] % 8 != 0)
	{
		memory[i - memory[i-1] / 8] = memory[i] + memory[i - 1];
		memory[i + memory[i] / 8 + 1] = memory[i - memory[i-1] / 8];
	}
	//in the right is free
	else if (i + 1 < this->size && memory[i + memory[i] / 8 + 2] % 8 != 0)
	{
		memory[i] = memory[i] + memory[i + memory[i] / 8 + 2];
		memory[i + memory[i] / 8 + 2 + memory[i + memory[i] / 8 + 2]] = memory[i];
	}
	//in left and right is free
	else if (i - 1 > 0 && memory[i - 1] % 8 != 0 && i + 1 < this->size && memory[i + memory[i] / 8 + 2] % 8 != 0)
	{
		memory[i - memory[i - 1] / 8] = memory[i] + memory[i - 1] + memory[i + memory[i] / 8 + 2];
		memory[i + memory[i] / 8 + 2 + memory[i + memory[i] / 8 + 2]] = memory[i - memory[i - 1] / 8];
	}
}	
