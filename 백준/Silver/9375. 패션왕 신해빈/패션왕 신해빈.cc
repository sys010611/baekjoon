#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main()
{
	int T;

	cin >> T; //테스트 케이스

	while (T--)
	{
		int n;
		cin >> n; //옷의 수
		cin.ignore();

		map<string, int> m; //<종류, 개수>

		for(int i = 0; i < n; i++)
		{

			string clothes; //옷의 명칭
			string a;
			string category; //옷의 종류

			getline(cin, clothes);
			stringstream ss(clothes);

			ss >> a >> category;

			if (m.find(category) != m.end()) //나왔던 종류일시
			{
				m[category]++; //개수++
			}
			else //처음 나오는 종류일시
			{
				m.insert(make_pair(category, 1)); //새로 추가, 개수 = 1
			}
		} //맵에 기록 완료

		int result = 1;

		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			result *= (iter->second + 1);
		}
		result -= 1;

		cout << result << "\n";
	}
}