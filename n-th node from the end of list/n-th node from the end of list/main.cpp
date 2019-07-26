#include <iostream>
#include <forward_list>

void find(const std::forward_list<int>& list, size_t n)
{
	auto main_it = list.begin();
	auto ref_it = list.begin();

	while (n--)
	{
		if (ref_it == list.end())
			throw std::invalid_argument("n is too big from list size");
		ref_it++;
	}

	while (ref_it != list.end())
	{
		main_it++;
		ref_it++;
	}
	std::cout << *main_it << std::endl;
}

int main()
{
	std::forward_list<int> list = { 1,2,3,4,5,6 };
	size_t n;
	while (true)
	{
		std::cout << "cin n >> "; std::cin >> n;
		try
		{
			find(list, n);
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
			exit(1);
		}
	}
	system("pause");
	return 0;
}