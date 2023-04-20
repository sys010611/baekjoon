#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int n;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

int average(int* arr)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	double result = sum / n;

	return round(result);
}

int middle(int arr[])
{
	return arr[n/2];
}

int frequent(int* arr)
{
	map<int,int> m;
	for (int i = 0; i < n; i++)
	{
		if (m.find(arr[i]) == m.end())
		{
			m[arr[i]] = 1;
		}
		else
		{
			m[arr[i]]++;
		}
	}

	vector<pair<int,int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), compare);


	if (v.size() == 1)
	{
		return v[0].first;
	}

	if (v[0].second > v[1].second)
	{
		return v[0].first;
	}

	int standard = v[0].second;
	vector<int> frequentNumbers;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second == standard)
		{
			frequentNumbers.push_back(v[i].first);
		}
	}
	sort(frequentNumbers.begin(), frequentNumbers.end());
	return frequentNumbers[1];
}

int range(int* arr)
{
	int* max = max_element(arr, arr+n);
	int* min = min_element(arr, arr+n);
	return *max - *min;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr+n);

	cout << average(arr) << endl;
	cout << middle(arr) << endl;
	cout << frequent(arr) << endl;
	cout << range(arr) << endl;
}