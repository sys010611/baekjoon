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

matrix MatMul(const matrix &a, const matrix &b)
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
				newMat[j][k] += (a[j][i] % 10000 * b[i][k] % 10000) % 10000;
				newMat[j][k] %= 10000;
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

	while (true)
	{
		cin >> n;

		if(n == -1) 
			break;
		else if (n == 0)
		{
			cout << 0 << endl;
			continue;
		}

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

		cout << resultMatrix[0][0] << endl;
	}
}