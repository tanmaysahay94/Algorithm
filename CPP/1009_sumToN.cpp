#include <bits/stdc++.h>

using namespace std;

void sumToN(vector<int>& v, int n, int sum)
{
	if (sum > n)
		return;
	if (sum == n)
	{
		for (int i = 0; i < (int) v.size(); i++)
			cout << v[i] << ' ';
		cout << endl;
		return;
	}
	int start;
	if (v.empty())
		start = 1;
	else
		start = v[v.size() - 1];
	for (int i = start; i < n and i + sum <= n; i++)
	{
		v.push_back(i);
		sumToN(v, n, sum + i);
		v.pop_back();
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	sumToN(v, n, 0);
	return 0;
}
