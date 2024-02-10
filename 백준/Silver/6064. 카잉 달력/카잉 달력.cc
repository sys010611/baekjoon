#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	int r = a % b;
	if (r == 0)
	{
		return b;
	}
	return gcd(b, r);
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int M,N,x,y;

		cin >> M >> N >> x >> y;

		int GCD = gcd(M,N);
		//cout << "GCD: " << GCD << endl;

		int maxYear = M*N/GCD; // 
		//cout << "maxYear: " << maxYear << endl;

		bool found = false;
		int currYear = x; //계속 M을 더할 것임
		do
		{
			//cout << "currYear: " << currYear << endl;
			if (currYear % N == y % N)
			{
				cout << currYear << endl;
				found = true;
				break;
			}

			currYear += M;
		}
		while (currYear <= maxYear);

		if(!found) cout << -1 << endl;
	}
}