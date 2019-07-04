#include <iostream>
#include <vector>
#include <algorithm>

int max(std::vector<int>& vec)
{
	int max = vec[0];
	for (int it : vec)
	{
		if (it > max)
			max = it;
	}
	return max;
}

// O(n^2) speed O(1) space
void find_duplicate_brute_force(std::vector<int>& vec) 
{
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (vec[i] == vec[j])
			{
				std::cout<<vec[i]<<" ";
			}
		}
	}
	std::cout << std::endl;
}

// O(n) speed O(n) space
void find_duplicate_count_iterations(std::vector<int>& vec) 
{
	int size = max(vec);
	std::vector<int> flags( size+1, 0 );

	for (int i = 0; i < vec.size(); ++i)
	{
		if (flags[vec[i]] > 0)
		{
			std::cout << vec[i] << " ";
		}
		else
		{
			flags[vec[i]]++;
		}
	}
	std::cout << std::endl;
}

// O(nlogn) speed O(1) space
void find_duplicate_sorted_array(std::vector<int> vec) 
{
	std::sort(vec.begin(), vec.end());
	for (int i=0;i<vec.size()-1;i++)
	{
		if (vec[i] == vec[i + 1])
		{
			std::cout << vec[i] << " ";
		}
	}
	std::cout << std::endl;
}

// O(n) speed O(1) space, it is work when vector have one duplicate
void find_duplicate_sum_of_the_elem(std::vector<int>& vec) 
{
	int sum_vec = 0;
	for (int i : vec)
	{
		sum_vec += i;
	}

	int sum_range = 0;
	int i = 1;
	while (i < vec.size())
	{
		sum_range += i++;
	}

	std::cout << sum_vec - sum_range << std::endl;
}



int main()
{
	std::vector<int> vec1{ 1,2,3,3 };
	std::vector<int> vec2{ 1,2,3,3,2,4,1 };

	find_duplicate_brute_force(vec1);
	find_duplicate_brute_force(vec2);

	find_duplicate_count_iterations(vec1);
	find_duplicate_count_iterations(vec2);

	find_duplicate_sorted_array(vec1);
	find_duplicate_sorted_array(vec2);

	find_duplicate_sum_of_the_elem(vec1);

	system("pause");
	return 0;
}