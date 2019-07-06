#include <iostream>

void is_even_ord_odd(int number)
{
	number & 1 ? std::cout << "number is odd\n" : std::cout << "number is even\n";
}

int main()
{
	int number;
	while (true)
	{
		std::cin >> number;
		is_even_ord_odd(number);
	}
	system("pause");
	return 1;
}