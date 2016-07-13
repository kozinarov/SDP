

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
	

	
	void add(const T& e)
	{
		if (_size >= _capacity)
		{
			extend();
		}

		elements[_size] = e;
		++_size;
	}

	
	void insertAtBeggining(const T& e)
	{
		if (_size >= _capacity)
		{
			extend();
		}
		if (_size + 1 >= _capacity)
			extend();

		if (_size == 0)
			extend();

		for (int i = _size; i > 0; i--)
		{
			elements[i] = elements[i-1];
		}
		elements[0] = e;
		++_size;
	}
	
	void copy(int times)
	{
	
		for (int i = 1; i <= times; i++)
		{
			if (i*_size >= _capacity)
			{
				extend();
			}
			for (int j = 0; j < _size; j++)
			{
				if (j + times*_size >= _capacity)
				{
					extend();
				}
				elements[j + i*_size] = elements[j];
			}
		}
		_size *= times;
	}
	
	T& get(int index)
	{
		return elements[index];
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

