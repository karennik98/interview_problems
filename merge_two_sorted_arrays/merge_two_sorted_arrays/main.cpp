#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> merge_two_sorted_array(std::vector<int>& arr1, std::vector<int>& arr2)
{
	size_t size1 = arr1.size();
	size_t size2 = arr2.size();
	std::vector<int> arr3;

	size_t i = 0, j = 0;

	while (i<size1 && j<size2)
	{
		if (arr1[i] < arr2[j])
			arr3.push_back(arr1[i++]);
		else
			arr3.push_back(arr2[j++]);
	}

	while (i < size1)
	{

		arr3.push_back(arr1[i++]);
	}

	while (j < size2)
	{

		arr3.push_back(arr2[j++]);
	}

	return arr3;
}

int main()
{
	std::vector<int> arr1{ 1,2,3,4 };
	std::vector<int> arr2{ 4,5,6,9 };
	std::vector<int> arr3 = merge_two_sorted_array(arr1, arr2);
	for (auto it : arr3)
	{
		std::cout << it << std::ends;
	}
	std::cout << std::endl;
	system("pause");
}