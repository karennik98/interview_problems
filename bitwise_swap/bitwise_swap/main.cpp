#include <iostream>

void swap(int& a, int& b)
{
	if (a != b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
}

int main()
{
	int a, b;
	while (true)
	{
		std::cout << "put a: "; std::cin >> a;
		std::cout << "put b: "; std::cin >> b;
		system("cls");
		std::cout << "before swap\n";
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "afther swap\n";
		swap(a, b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl<<std::endl;
	}
	system("pause");
	return 0;
}