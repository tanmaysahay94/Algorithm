#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

bool isPalin(int n)
{
	string s;
	while (n)
	{
		s += (n%10) + '0';
		n/=10;
	}
	bool ret = true;
	for (int i = 0; ret and i < ((int)s.length())/2; i++)
		if (s[i] != s[s.length() - i - 1])
			ret = false;
	return ret;
}

int main()
{
	vector<int> pl;
	vector<bool> is(998002);
	optimizeIO();
	for (int i = 100; i < 1000; i++)
		for (int j = 100; j < 1000; j++)
			if (isPalin(i * j))
				if (!is[i * j])
					pl.push_back(i * j), is[i * j] = true;;
	sort(pl.begin(), pl.end());
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>::iterator idx;
		idx = lower_bound(pl.begin(), pl.end(), n);
		idx--;
		cout << *idx << endl;
	}
	return 0;
}
