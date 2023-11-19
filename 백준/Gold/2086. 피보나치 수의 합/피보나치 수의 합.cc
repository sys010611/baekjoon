#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;

matrix M;

vector<int> GetBinArr(long long n) //2진수 변환 (거꾸로 되어있음)
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

matrix MatMul(const matrix& a, const matrix& b)
{
	matrix newMat(2);
	newMat[0].resize(2);
	newMat[1].resize(2);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				newMat[j][k] += (a[j][i] % 1000000000 * b[i][k] % 1000000000) % 1000000000;
				newMat[j][k] %= 1000000000;
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
	long long a, b;
	cin >> a >> b;

	b++;

	M.push_back({ 1,1 });
	M.push_back({ 1,0 });

	vector<int> binarrA = GetBinArr(a); 
	vector<int> binarrB = GetBinArr(b);

	matrix resultMatrixA;
	matrix resultMatrixB;
	resultMatrixA.push_back({ 1,0 }); //단위행렬
	resultMatrixA.push_back({ 0,1 });
	resultMatrixB.push_back({ 1,0 }); //단위행렬
	resultMatrixB.push_back({ 0,1 });

	matrix m_power = M;

	for (int i = 0; i < binarrB.size(); i++)
	{
		if (i < binarrA.size()) // 인덱스 초과 예외처리
		{
			if (binarrA[i] == 1)
			{
				resultMatrixA = MatMul(m_power, resultMatrixA); // M^(n-1) 구하기
			}
		}
		if (binarrB[i] == 1)
		{
			resultMatrixB = MatMul(m_power, resultMatrixB); // M^(n-1) 구하기
		}
		m_power = MatMul(m_power, m_power);
	}

	long long FiboA = resultMatrixA[0][0]; // F A+1
	long long FiboB = resultMatrixB[0][0]; // F B+2

	cout << (FiboB - FiboA + 1000000000) % 1000000000;
}