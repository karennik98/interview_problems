#include <iostream>
#include <stack>

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void show_arr(int *arr, size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << std::ends;
	}
	std::cout << std::endl;
}

void reverse_array(int* arr, size_t left, size_t right)
{
	for (size_t i = left; i < right / 2; ++i)
	{
		swap(arr[i], arr[right - i - 1]);
	}
}

void reverse_array_recursive(int* arr, size_t left, size_t right)
{
	if (left < right)
	{
		swap(arr[left], arr[right]);
		reverse_array_recursive(arr, left + 1, right - 1);
	}
	return;
}

void reverse_array_using_stack(int* arr, size_t size)
{
	std::stack<int> stack;
	for (int i = 0; i < size; ++i)
	{
		stack.push(arr[i]);
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = stack.top();
		stack.pop();
	}
}

int main()
{
	int arr[6] = { 1,2,3,4,5,6 };

	std::cout << "initial array\n";
	show_arr(arr, 6);

	std::cout << "in place method\n";
	reverse_array(arr, 0, 6);
	show_arr(arr, 6);

	/*std::cout << "second in place method\n";
	reverse_array(arr, 0, 3);
	reverse_array(arr, 3, 6);
	reverse_array(arr, 0, 6);
	show_arr(arr, 6);*/

	std::cout << "recursive\n";
	reverse_array_recursive(arr, 0, 5);
	show_arr(arr, 6);

	std::cout << "using stack\n";
	reverse_array_using_stack(arr, 6);
	show_arr(arr, 6);

	system("pause");
	return 0;
}