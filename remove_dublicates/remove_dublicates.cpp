#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
void show(std::vector<T> vec)
{
	for (const auto& i : vec)
	{
		std::cout << i << std::ends;
	}
	std::cout << std::endl;
}

template<typename T>
void remove_dublicates_from_array(std::vector<T>& vec)
{
	std::sort(vec.begin(),vec.end());
	auto last = std::unique(vec.begin(), vec.end());
	vec.erase(last, vec.end());
}

int main()
{
	std::vector<char> vec{'d','d','a','e','q'};
	remove_dublicates_from_array<char>(vec);
    show<char>(vec);
}
