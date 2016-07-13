#include <iostream>
#include "Memory.h"
using namespace std;

int main()
{
	Memory obj(1024);

	long long* a=obj.MyMalloc(10);
	long long* header1 = a-2;
	obj.MyFree(a);
	cout << *header1 << endl;
	return 0;
}