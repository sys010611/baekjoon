#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> positives;
	vector<int> negatives;
	int zeros = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;

		if(input > 0)
			positives.push_back(input);
		else if(input < 0)
			negatives.push_back(input);
		else if(input == 0)
			zeros++;
	}

	sort(positives.begin(), positives.end(), greater<int>());
	sort(negatives.begin(), negatives.end(), less<int>());

	//cout << endl;
	//for(auto num : negatives ) cout << num << endl;

	int result = 0;

	//음수는 작은 것부터 서로 곱하기
	for (int i = 0; i < negatives.size();)
	{
		int neg1 = negatives[i];
		if (i + 1 >= negatives.size())
		{
			if (zeros > 0)
			{
				break;
			}
			else
			{
				result += neg1;
				break;
			}
		}
		else
		{
			int neg2 = negatives[i+1];
			result += neg1*neg2;
			i+=2;
		}
	}

	//양수는 큰 것부터 서로 곱해서 더해주기
	for (int i = 0; i < positives.size();)
	{
		int pos1 = positives[i];
		if (i + 1 >= positives.size())
		{
			result += pos1;
			break;
		}
		else
		{
			int pos2 = positives[i + 1];
			if (pos2 != 1)
			{
				result += pos1 * pos2;
				i += 2;
			}
			else
			{
				result += pos1;
				i++;
			}
		}
	}

	cout << result;
}