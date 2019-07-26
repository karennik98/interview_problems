#include <iostream>
#include <string>
#include <vector>

int mat[5][4] {
	{1,1,1,1},
	{0,0,1,1},
	{0,0,0,0},
	{1,1,1,1},
    {1,1,1,1}
};

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


void fill_matrix(int** mat, int row, int col)
{
	int* arr1 = new int[row];
	int* arr2 = new int[col];

	for (int i = 0; i < row; ++i)
		arr1[i] = 1;
	for (int j = 0; j < col; ++j)
		arr2[j] = 1;

	for (int i = 0; i < row; ++i)
		for(int j=0;j<col;++j)
			if (mat[i][j] == 0)
			{
				arr1[i] = 0;
				arr2[j] = 0;
			}
	for (int i = 0; i < row; ++i)
	{
		for(int j=0;j<col;++j)
		{
			if (arr1[i] == 0 || arr2[j] == 0)
			{
				mat[i][j] = 0;
			}
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
	fill_matrix(mat, n, m);
	print(mat, n, m);
	system("pause");
	return 0;
}