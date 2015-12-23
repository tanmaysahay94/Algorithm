#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL get_min(vector<LL>& v)
{
	LL ans = LLONG_MAX;
	for (auto f: v)
		ans = min(ans, f);
	return ans;
}

int main()
{
	LL d1, d2, d3;
	cin >> d1 >> d2 >> d3;
	vector<LL> v;
	v.push_back(d1 + d2 + d3);
	v.push_back(d1 + d3 + d3 + d1);
	v.push_back(d2 + d2 + d1 + d1);
	v.push_back(d2 + d3 + d3 + d2);
	cout << get_min(v);
	return 0;
}
