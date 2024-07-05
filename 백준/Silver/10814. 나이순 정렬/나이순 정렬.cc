#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info
{
	int age;
	string name;
	int idx;
	info(int a, string n, int i)
	{
		age = a;
		name=n;
		idx=i;
	}
};

bool compare(info& a, info& b)
{
	if (a.age != b.age)
	{
		return a.age < b.age;
	}
	else
	{
		return a.idx<b.idx;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<info> vec;


	int n;

	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int age; string name;
		cin>>age >> name;
		vec.push_back(info(age,name,i));
	}

	sort(vec.begin(), vec.end(), compare);

	for (auto item : vec)
	{
		cout << item.age << " " << item.name << '\n';
	}
}