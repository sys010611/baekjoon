#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<int> A; //내구도
vector<bool> occupied;

void Rotate()
{
	bool occupied_temp = occupied[2*N-1];
	int A_temp = A[2*N-1];

	for (int i = 2 * N - 1; i >= 1; i--)
	{
		occupied[i] = occupied[i-1];
		A[i] = A[i-1];
	}
	occupied[0] = occupied_temp;
	A[0] = A_temp;

	if(occupied[N-1])
		occupied[N-1] = false;
}
void Move()
{
	for (int i = N - 1; i >= 1; i--)
	{
		if (occupied[i - 1] && !occupied[i])
		{
			if (A[i] > 0)
			{
				occupied[i] = true;
				occupied[i-1] = false;
				A[i]--;
			}
		}
	}

	if(occupied[N-1])
		occupied[N-1] = false;
}
void Put()
{
	if (A[0] > 0)
	{
		occupied[0] = true;
		A[0]--;
	}
}
int Check()
{
	int count = 0;
	for (int i = 0; i < 2 * N; i++)
	{
		if(A[i] <= 0)
			count++;
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	A.resize(2*N);
	occupied.resize(2*N);

	for (int i = 0; i < 2 * N; i++)
	{
		cin >> A[i];
	}

	for (int t = 1; ; t++)
	{
		Rotate();
		Move();
		Put();

		//cout << "t : " << t << endl;
		//for (int i = 0; i < 2 * N; i++)
		//{
		//	cout << A[i] << " ";
		//}
		//cout << endl;

		if (Check() >= K)
		{
			cout << t;
			return 0;
		}
	}
}