#include <iostream>

std::pair<int,int> brute_force_find(int* arr, int k,int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if ((arr[i] + arr[j]) == k)
				return { arr[i], arr[j] };
		}
	}
	return { 0,0 };
}

int& fun()
{
	static int x = 10;
	return x;
}

void f(int const *p)
{
	std::cout << *p << std::endl;
	int value = -123;
	p = &value;
	std::cout << *p << std::endl;
}
using std::cout;
using std::endl;
class A
{
public:
	virtual void stuff(int i = 5) { cout << "A " << i << endl; }
};
class B : public A
{
public:
	virtual void stuff(int i = 10) { cout << "B " << i << endl; }
};
int main(int argc, char *argv[])
{
	const int a = 9;
	const int& b = a;
	system("pause");
	return 0;
}

//int main()
//{
//	int value = 5;
//	int* pvalue = &value;
//	f(pvalue);
//	std::cout << *pvalue << std::endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//int arr[] = { 1,2,3,18,2 };
//	//auto pair = brute_force_find(arr, 2, 5);
//	//std::cout << "{ " << pair.first << "," << pair.second << " }" << std::endl;
//	//fun() = 40;
//	//std::cout << fun() << std::endl;
//	system("pause");
//	return 0;
//}