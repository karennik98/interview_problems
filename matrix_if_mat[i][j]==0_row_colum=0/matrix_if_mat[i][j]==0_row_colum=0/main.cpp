#include <iostream>
#include <string>
#include <vector>

void print(int **mat, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void fill(int ** mat, int n, int m)
{
	std::vector<std::pair<int, int>> vec;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == 0)
			{
				vec.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		std::pair<int, int> p = vec[i];
		for (int k = 0; k < m; k++)
		{
			mat[p.first][k] = 0;
		}
		for (int j = 0; j < n; j++)
		{
			mat[j][p.second] = 0;
		}
	}
}

int main()
{
	const int n = 4;
	const int m = 5;
	int** mat = new int*[n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = 1;
		}
	}
	mat[0][0] = 0;
	mat[3][4] = 0;
	print(mat, n, m);
	fill(mat, n, m);
	print(mat, n, m);
	system("pause");
	return 0;
}