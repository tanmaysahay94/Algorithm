#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<pair<long long, long long> > v;
int foo[2];
bool truth[8];

void compete(int idx, int player, int n)
{
	if (idx == n)
	{
		foo[player]++;
		return;
	}
	int tmp(0);
	for (int j = n; j >= v[idx].first; j--)
	{
		if (truth[j])
			tmp = 1 - tmp;
		else if (j <= v[idx].second)
		{
			truth[j] = true;
			compete(idx + 1, tmp ^ player, n);
			truth[j] = false;
		}
	}
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;
		foo[0] = foo[1] = 0;
		compete(0, 0, n);
		if (foo[0] < foo[1])
			cout << "Fedor\n";
		else if (foo[0] > foo[1])
			cout << "Alex\n";
		else
			cout << "Draw\n";
	}
	return 0;
}
