#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

typedef vector<vector<int>> matrix;

matrix result;

matrix GetMap()
{
	matrix newMat(8);
	for (int i = 0; i < 8; i++)
	{
		newMat[i].resize(8);
	}

	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			newMat[i][j] = 0;

	newMat[0][1] = 1;
	newMat[0][3] = 1;
	newMat[1][0] = 1;
	newMat[1][2] = 1;
	newMat[1][3] = 1;
	newMat[2][1] = 1;
	newMat[2][3] = 1;
	newMat[2][4] = 1;
	newMat[2][5] = 1;
	newMat[3][0] = 1;
	newMat[3][1] = 1;
	newMat[3][2] = 1;
	newMat[3][5] = 1;
	newMat[4][2] = 1;
	newMat[4][5] = 1;
	newMat[4][6] = 1;
	newMat[5][2] = 1;
	newMat[5][3] = 1;
	newMat[5][4] = 1;
	newMat[5][7] = 1;
	newMat[6][4] = 1;
	newMat[6][7] = 1;
	newMat[7][5] = 1;
	newMat[7][6] = 1;

	return newMat;
}

matrix MatMul(const matrix& a, const matrix& b, int size)
{
	matrix newMat(size);
	for (int i = 0; i < size; i++)
		newMat[i].resize(size);

	for (int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			newMat[i][j] = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				newMat[j][k] += (a[j][i] * b[i][k]) % 1000000007;
				newMat[j][k] = newMat[j][k] % 1000000007;
			}
		}
	}
	return newMat;
}

void PrintMatrix(matrix M)
{
	for (auto i = M.begin(); i != M.end(); i++)
	{
		for (auto j = i->begin(); j != i->end(); j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
}

int main()
{
	int d;
	cin >> d;

	matrix defaultMap = GetMap();
	result = defaultMap;
	//PrintMatrix(result);
	
	for (int i = 0; i < d-1; i++)
	{
		result = MatMul(result, defaultMap,8);
	}

	//PrintMatrix(result);

	cout << (result[0][0]);
}