#pragma once
template <typename T>
class DynamicArray {

	T* elements;
	int _size;
	int _capacity;

	void extend()
	{
		_capacity = _capacity * 2;
		T* copy = new T[_capacity];

		for (int i = 0; i < _size; ++i)
		{

			copy[i] = elements[i];

		}
		delete[] elements;
		elements = copy;
	}
public:

	DynamicArray()
	{
		_size = 0;
		_capacity = 1;

		elements = new T[_capacity];
	}


	~DynamicArray()
	{
		Free();
	}

	T& operator[](size_t index)
	{
		if (index >= _size)
		{
			cout << "Index out of bounds" << endl;
		}

		return elements[index];
	}

	
	void push_back(const T& e)
	{
		if (_size >= _capacity)
		{
			extend();
		}

		elements[_size] = e;
		++_size;
	}


	int size() const
	{
		return _size;
	}

	void Free()
	{
		delete[] elements;

		elements = new T[_capacity];
		_size = 0;
		_capacity = 1;
	}
};
