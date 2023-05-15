#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<long long> line;

long long cutLines(long long length)
{
	long long count = 0;
	for (int i = 0; i < line.size(); i++)
		count += (line[i] / length);
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;


	for (int i = 0; i < k; i++)
	{
		long long input; cin >> input;
		line.push_back(input);
	}

	//자르는 길이의 구간
	long long min = 1;
	long long max = 2147483648;
	long long mid;

	long long count;
	while (max > min + 1)
	{
		mid = (min + max) / 2;
		count = cutLines(mid);

		if (count < n) //너무 적게 만들어짐 (더 짧게 자르기)
		{
			max = mid;
		}
		else if (count >= n) //너무 많이 만들어짐 (더 길게 자르기) (count가 맞아도 더 길게 잘라보기)
		{
			min = mid;
		}
	}

	
	cout << min;

	return 0;
}


