#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;

int N;
long long B;

void InitMatrix(matrix& mat, int size)
{
	mat.resize(size);
	for (int i = 0; i < size; i++)
		mat[i].resize(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mat[i][j] = 0;
}

vector<int> GetBinArr(long long n) //2진수 변환 (거꾸로 되어있음) (1, 2, 4, 8...)
{
	vector<int> binarr;
	while (n > 0)
	{
		if (n % 2 == 0)
			binarr.push_back(0);
		else
			binarr.push_back(1);

		n /= 2;
	}
	return binarr;
}

matrix MatMul(const matrix &a, const matrix &b)
{
	matrix newMat(N);
	for (int i = 0; i < N; i++)
		newMat[i].resize(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				newMat[j][k] += (a[j][i] % 1000 * b[i][k] % 1000) % 1000;
				newMat[j][k] %= 1000;
			}
		}
	}
	return newMat;
}

void PrintMatrix(const matrix& M)
{
	for (auto i = M.begin(); i != M.end(); i++)
	{
		for (auto j = i->begin(); j != i->end(); j++)
		{
			cout << *j << " ";
		}
		if (i != M.end()-1)
			cout << endl;
	}
}

int main()
{
	cin >> N >> B;

	vector<int> BinArr = GetBinArr(B);

	matrix A;
	InitMatrix(A, N);

	for(int i=0; i<N;i++)
		for(int j=0;j<N;j++)
			cin >> A[i][j];

	////B를 2진수로 나타내기
	//for (auto it = BinArr.begin(); it != BinArr.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	vector<matrix> PoweredMatrix;
	PoweredMatrix.push_back(A);

	while (PoweredMatrix.size() != BinArr.size()) // A, A^2, A^4, .... 저장
	{
		PoweredMatrix.push_back(MatMul(*(PoweredMatrix.end()-1), *(PoweredMatrix.end()-1)));
	}

	//cout << endl;
	//for (auto it = PoweredMatrix.begin(); it != PoweredMatrix.end(); it++)
	//{
	//	PrintMatrix(*it);
	//	cout << endl;
	//}

	matrix ResultMatrix;
	InitMatrix(ResultMatrix, N);
	for(int i=0;i<N;i++)
		ResultMatrix[i][i] = 1;

	for (int i = 0; i < BinArr.size(); i++)
	{
		if (BinArr[i] == 1)
		{
			ResultMatrix = MatMul(ResultMatrix, PoweredMatrix[i]);
		}
	}

	PrintMatrix(ResultMatrix);
}