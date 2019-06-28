#include <iostream>
#include <algorithm>

struct point
{
	int x;
	int y;
	
	point(int x, int y)
		: x(x)
		, y(y)
	{
	}

	point() = default;

};

size_t square(int x)
{
	return x * x;
}

void sort(int& a, int& b, int& c)
{
	int arr[] = { a,b,c };
	std::sort(arr, arr + 3);
	a = arr[0];
	b = arr[1];
	c = arr[2];
	//std::cout << a << " " << b << " " << c << std::endl;
}

void order(int& a, int& b, int& c)
{
	int arr[] = { a,b,c };

}

int side_square(point& p1, point& p2)
{
	return square(p1.x - p2.x) + square(p1.y - p2.y);
}

bool is_triangle(int a, int b, int c)
{
	a = std::pow(a, 0.5);
	b = std::pow(b, 0.5);
	c = std::pow(c, 0.5);
	return (a + b > c && a + c > b && c + b > a);
}

bool is_right_angle(int a, int b, int c)
{
	return(c == a + b);
}

bool is_equilateral(int a, int b, int c)
{
	return a == b && b == c;
}

bool is_isosceles(int a, int b, int c) 
{
	return(a == b || c == b );
}

bool is_acute_angle(int a, int b, int c)
{
	return(a + b > c);
}

bool is_obtuse_angle(int a, int b, int c)
{
	return a + b < c;
}

int main()
{
	////point p1(0, 1);
	////point p2(1, 4);
	////point p3(3, 1); //-->> acute angle
	//
	////point p1(1, 1);
	////point p2(3, 2);
	////point p3(6, 2); //-->> obtuse angle

	//point p1(1, 2);
	//point p2(1, 7);
	//point p3(6, 2); //-->> right angle, isosceles

	//int a = side_square(p1, p2);
	//int b = side_square(p1, p3);
	//int c = side_square(p2, p3);

	//std::cout << a << " " << b << " " << c << std::endl;

	//std::cout << is_triangle(a, b, c) << std::endl;
	//std::cout << is_equilateral(a, b, c) << std::endl;
	//std::cout << is_isosceles(a, b, c) << std::endl;

	//sort(a, b, c);

	//std::cout << is_right_angle(a, b, c)<<std::endl;
	//std::cout << is_acute_angle(a, b, c) << std::endl;
	//std::cout << is_obtuse_angle(a, b, c) << std::endl;

	int a = 9;
	int& b = a;
	std::cout << &b << std::endl;
	int c = 8;
	b = c;
	std::cout << &b << std::endl;

	system("pause");
	return 0;
}