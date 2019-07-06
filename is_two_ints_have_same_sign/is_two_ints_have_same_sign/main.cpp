#include <iostream>
#include <bitset>

void print_32_bit_binary(int n)
{
	std::cout << std::bitset<32>(n) << std::endl;
}

void is_same_sign(int n1, int n2)
{
	std::cout << std::bitset<32>(n1 ^ n2) << std::endl;
	(n1^n2) > 0 ? std::cout << "have same sign\n" : std::cout << "have different sign\n";
}

int main()
{
	int n1, n2;
	while (true)
	{
		std::cin >> n1;
		print_32_bit_binary(n1);
		std::cin >> n2;
		print_32_bit_binary(n2);
		is_same_sign(n1, n2);
	}
	system("pause");
	return 0;
}