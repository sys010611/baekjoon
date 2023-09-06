#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int maxDP[2][3];
	int minDP[2][3];

	for(int i=0;i<2;i++)
		for (int j = 0; j < 3; j++)
		{
			maxDP[i][j] = 0; minDP[i][j] = 0;
		}

	int a,b,c;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		
		maxDP[1][0] = a + max(maxDP[0][0], maxDP[0][1]);
		maxDP[1][1] = b + max({maxDP[0][0], maxDP[0][1], maxDP[0][2]});
		maxDP[1][2] = c + max(maxDP[0][1], maxDP[0][2]);

		minDP[1][0] = a + min(minDP[0][0], minDP[0][1]);
		minDP[1][1] = b + min({minDP[0][0], minDP[0][1], minDP[0][2]});
		minDP[1][2] = c + min(minDP[0][1], minDP[0][2]);

		copy(maxDP[1], maxDP[1] + 3, maxDP[0]);
		copy(minDP[1], minDP[1] + 3, minDP[0]);
	}

	cout << *max_element(maxDP[0], maxDP[0] + 3) << " " << *min_element(minDP[0], minDP[0] + 3);
}