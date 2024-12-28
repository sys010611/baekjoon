#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;


signed main()
{
	int score[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> score[i];
	}
	sort(score, score + 3);

	cout << score[1] + score[2];
}

