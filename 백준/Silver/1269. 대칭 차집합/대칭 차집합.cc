#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;


int main()
{
	int A,B; //집합 A, B의 원소의 개수
	cin >> A >> B;

	set<int> a; //집합연산을 할 set
	set<int> b;
	vector<int> aList; //원본을 저장할 배열
	vector<int> bList;

	while (A--)
	{
		int input;
		cin >> input;
		a.insert(input);
		aList.push_back(input);
	}

	while (B--)
	{
		int input;
		cin >> input;
		b.insert(input);
		bList.push_back(input);
	}

	for (int element : bList)
	{
		a.erase(element);
	}
	for (int element : aList)
	{
		b.erase(element);
	}

	cout << a.size() + b.size();
}