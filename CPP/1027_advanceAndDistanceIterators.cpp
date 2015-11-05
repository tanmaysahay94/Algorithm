#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	set<int> S;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		S.insert(val);
		auto it1 = S.begin();
		auto it2 = S.find(val);
		cout << distance(it1, it2) << endl;
		advance(it1, distance(it1, it2));
		assert(it1 == it2);
	}
	return 0;
}
