#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A,B,C;
	cin >> A >> B >> C;

	cout << (A + B) % C << endl << ((A % C) + (B % C)) % C<<endl<<(A*B) % C<<endl<<((A % C) *(B % C)) % C;
}
