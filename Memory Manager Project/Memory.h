#pragma once
class Memory
{
private:
	size_t size;
	long long* memory;

public:
	Memory(size_t size);
	~Memory();

	long long* MyMalloc(size_t Size);
	void MyFree(long long* pBlock);
};

