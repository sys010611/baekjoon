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
				newMat[j][k] += (a[j][i] % 1000000007 * b[i][k] % 1000000007) % 1000000007;
				newMat[j][k] %= 1000000007;
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
	long long n;
	cin >> n;

	n--;

	M.push_back({ 1,1 });
	M.push_back({ 1,0 });

	vector<int> binarr = GetBinArr(n);

	matrix resultMatrix;
	resultMatrix.push_back({ 1,0 }); //단위행렬
	resultMatrix.push_back({ 0,1 });

	matrix m_power = M;

	for (int i = 0; i < binarr.size(); i++)
	{
		if (binarr[i] == 1)
		{
			resultMatrix = MatMul(m_power, resultMatrix); // M^(n-1) 구하기
		}
		m_power = MatMul(m_power, m_power);
	}

	long long FiboN = resultMatrix[0][0];
	long long FiboNMinus1 = resultMatrix[0][1];

	if ((n+1) % 2 == 1) // 원래 n이 홀수
		cout << FiboN - 1;
	else // 원래 n이 짝수
		cout << (FiboN % 1000000007 + FiboNMinus1 % 1000000007 - 1) % 1000000007;
}