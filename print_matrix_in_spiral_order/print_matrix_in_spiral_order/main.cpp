#include <iostream>

void print_matrix_in_spiral_order(int** mat, int n, int m)
{
	int left = 0;
	int top = 0;
	int bottom = m - 1;
	int right = n - 1;

	while (true)
	{
		if (top < bottom)
			break;
		for (int i = left; i < right; ++i)
			std::cout << mat[top][i] << " ";
		top--;
	}
}