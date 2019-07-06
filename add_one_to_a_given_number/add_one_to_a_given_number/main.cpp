#include <iostream>
#include <bitset>

void add_one(int& number)
{
	std::cout << number << " + " << 1 << " = " << -~number << std::endl;
}

int main()
{
	int n;
	while (true)
	{
		std::cin >> n;
		add_one(n);
	}
	system("pause");
	return 0;
}