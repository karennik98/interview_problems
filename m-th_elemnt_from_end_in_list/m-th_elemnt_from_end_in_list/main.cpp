#include <iostream>
#include <forward_list>

int size(std::forward_list<int>& list)
{
	int size = 0;
	auto it = list.begin();
	while (it!=list.end())
	{
		size++;
		it++;
	}

	return size;
}

auto find(std::forward_list<int>& list, int m)
{
	int n = size(list) - m;
	auto it = list.begin();
	if (n > 0)
	{
		while (n)
		{
			n--;
			it ++;
		}
		return it;
	}
	throw std::invalid_argument("argumen wrong");
}

int main()
{
	std::forward_list<int> list{ 1,4,5,6,3,5 };
	auto it = find(list, 5);
	std::cout << *it << std::endl;
	system("pause");
	return 0;
}