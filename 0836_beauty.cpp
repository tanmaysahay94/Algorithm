#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int f(int n)
{
	if (not n)
		return 0;
	int cnt = 0;
	while (n % 2 == 0)
	{
		n >>= 1;
		cnt++;
	}
	return cnt;
}

int main()
{
	optimizeIO();
	vector<int> v[40];
	int val;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		int foo = val;
		int j = 0;
		while (foo)
		{
			if (foo & 1)
				v[j].push_back(val);
			j++;
			foo >>= 1;
		}
	}
	vector<int> u(40);
	for (int i = 0; i < 40; i++)
	{
		if (not v[i].size())
		{
			u[i] = 0;
			continue;
		}
		int foo = v[i][0];
		for (int j = 1; j < (int) v[i].size(); j++)
			foo &= v[i][j];
		u[i] = foo;
	}
	int ansidx = 0, currpow2 = -1;
	for (int i = 0; i < 40; i++)
	{
		int foo = f(u[i]);
		if (foo > currpow2)
		{
			currpow2 = foo;
			ansidx = i;
		}
		else if (foo == currpow2)
			if (v[i].size() > v[ansidx].size())
				ansidx = i;
	}
	cout << v[ansidx].size() << '\n';
	for (int i = 0; i < (int) v[ansidx].size(); i++)
		cout << v[ansidx][i] << ' ';
	cout << endl;
	return 0;
}
