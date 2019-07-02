#include <iostream>

//First way
template<int n>
struct Fac {
	enum  { result = n * Fac<n - 1>::result };
};

template<>
struct Fac<0> {
	enum  { result = 1};
};

//Second way
template<unsigned int n>
struct fac {
	static const unsigned int result = n * fac<n - 1>::result;
};

template<>
struct fac<0> {
	static const unsigned int result = 1;
};

int main()
{
	std::cout << Fac<5>::result << std::endl;
	std::cout << fac<5>::result << std::endl;
	system("pause");
	return 0;
}