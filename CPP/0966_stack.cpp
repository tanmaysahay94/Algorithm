#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	multiset<int> sz;
	sz.insert(-1);
	for (int i = 0; i < n; i++)
	{
		int cap = v[i];
		multiset<int>::iterator it = sz.upper_bound(cap);
		it--;
		int val = *it;
		if (val != -1)
		{
			sz.erase(it);
			sz.insert(val + 1);
		}
		else
			sz.insert(1);
	}
	cout << sz.size() - 1;
	return 0;
}
