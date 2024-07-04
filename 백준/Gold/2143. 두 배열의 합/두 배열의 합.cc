#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

int T; // target
int n, m;

vector<int> A;
vector<int> B;

vector<int> A_sum;
vector<int> B_sum;

vector<int> A_partitial_sum;
vector<int> B_partitial_sum;

void print()
{
	cout << "A 누적합 목록: " << endl;
	for (auto item : A_sum)
	{
		cout << item << endl;
	}
	cout << "B 누적합 목록: " << endl;
	for (auto item : B_sum)
	{
		cout << item << endl;
	}

	cout << "A 부분누적합 목록: " << endl;
	for (auto item : A_partitial_sum)
	{
		cout << item << ' ';
	}
	cout << endl;
	cout << "B 부분누적합 목록: " << endl;
	for (auto item : B_partitial_sum)
	{
		cout << item << ' ';
	}
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	cin >> n;
	A.resize(n);
	for(int i=0;i<n;i++)
		cin >> A[i];

	cin >> m;
	B.resize(m);
	for (int i = 0; i < m; i++)
		cin >> B[i];

	int currASum = 0;
	for (int i = 0; i < n; i++)
	{
		currASum += A[i];
		A_sum.push_back(currASum);
	}

	int currBSum = 0;
	for (int i = 0; i < m; i++)
	{
		currBSum += B[i];
		B_sum.push_back(currBSum);
	}


	for (int i = A_sum.size()-1; i > -1; i--)
	{
		for (int j = i - 1; j > -1; j--)
		{
			A_partitial_sum.push_back(A_sum[i] - A_sum[j]);
		}
		A_partitial_sum.push_back(A_sum[i]);
	}
	//sort(A_partitial_sum.begin(), A_partitial_sum.end());

	for (int i = B_sum.size()-1; i > -1; i--)
	{
		for (int j = i - 1; j > -1; j--)
		{
			B_partitial_sum.push_back(B_sum[i] - B_sum[j]);
		}
		B_partitial_sum.push_back(B_sum[i]);
	}
	sort(B_partitial_sum.begin(), B_partitial_sum.end());

	int result = 0;
	// A 부분누적합에서 하나 고르고, B에서 이분탐색하고.. 반복
	for (int i = 0; i < A_partitial_sum.size(); i++)
	{
		int a = A_partitial_sum[i];
		int b = T - a; //아직 있는지 모름

		auto b_it_lb = lower_bound(B_partitial_sum.begin(), B_partitial_sum.end(), b);

		if(b_it_lb == B_partitial_sum.end()) // 못 찾았을 경우 바로 continue;
			continue;
		
		
		if(*b_it_lb == b) // 찾았을 경우
		{
			auto b_it_ub = upper_bound(B_partitial_sum.begin(), B_partitial_sum.end(), b);

			result += (b_it_ub - b_it_lb);
		}
	}
	cout << result;
	
}