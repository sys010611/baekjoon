#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long N; //나무의 개수
	long long M; //할당량
	int H = -1; //절단기의 높이
	long long sum = 0; //자른 나무의 양

	vector<long long> trees;

	cin >> N >> M;

	for (int i = 0; i < N; i++) //각 나무의 높이 입력
	{
		long long tree;
		cin >> tree;
		trees.push_back(tree);
	}

	/*for (int i = 0; i < trees.size(); i++) //입력한 나무들 확인
	{
		cout << "나무 " << i+1 << ": " << trees[i] << endl;
	}*/

	int min = 0;
	//cout << "min: " << min << endl;
	int max = 1000000000; 
	//cout << "max: " << max << endl;

	while (min + 1 < max)
	{
		sum = 0;
		H = (min + max) / 2;

		for (int i = 0; i < N; i++) //나무 자르기
		{
			if (H < trees[i])
				sum += trees[i] - H;
			else
				continue;
		}

		if (sum > M)
			min = H;
		else if (sum < M)
			max = H;
		else
		{
			cout << H << endl;
			return 0;
		}
		//cout << "min: " << min << ", " << "max: " << max << endl;
	}

	cout << min;
}