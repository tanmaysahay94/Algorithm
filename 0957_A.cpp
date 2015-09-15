#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> v(10);
	for (int i = 0; i < 10; i++)
		cin >> v[i];
	sort(v.rbegin(), v.rend());
	cout << v[0] + v[2] + v[4] << endl;
	return 0;
}
