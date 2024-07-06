#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

vector<int> A, B, C, D;
vector<int> A_B, C_D;

int n;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;

		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			int aPb = A[i]+B[j];
			A_B.push_back(aPb);
		}
	}
	for (int i = 0; i < C.size(); i++)
	{
		for (int j = 0; j < D.size(); j++)
		{
			int cPd = C[i] + D[j];
			C_D.push_back(cPd);
		}
	}


	int result = 0;

	sort(C_D.begin(), C_D.end());
	for (int i = 0; i < A_B.size(); i++)
	{
		int aPlusB = A_B[i];

		// C + D에서 -aPlusB인 값을 찾고 싶음
		auto it_lb = lower_bound(C_D.begin(), C_D.end(), -aPlusB);

		if(it_lb == C_D.end()) // 못 찾았을 경우
			continue;
		else // 찾았을 경우에도 답이 여러개 있을 수 있음
		{
			int cPlusD = *it_lb;
			if (aPlusB + cPlusD == 0) // lb가 답을 나타내고 있는지까지 확인 후
			{
				auto it_ub = upper_bound(C_D.begin(), C_D.end(), -aPlusB);
				result += (it_ub - it_lb);
			}
		}
	}

	cout << result;
}