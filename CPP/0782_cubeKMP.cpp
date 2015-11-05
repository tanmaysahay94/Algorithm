#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<long long> a, b, table;

int kmp()
{
	table.resize(b.size()+1);
	int ans = 0;
	table[0] = table[1] = 0;
	for (int i = 2; i < (int) table.size(); i++)
	{
		int j = table[i - 1];
		for (;;)
		{
			if (b[i - 1] == b[j])
			{
				table[i] = j + 1;
				break;
			}
			else if (j == 0)
			{
				table[i] = 0;
				break;
			}
			else
				j = table[j];
		}
	}
	int i = 0, j = 0;
	for (;;)
	{
		if (j == (int)a.size())
			break;
		if (a[j] == b[i])
		{
			i++;
			j++;
			if (i == (int)b.size())
			{
				ans++;
				i = table[i];
			}
		}
		else if (i > 0)
			i = table[i];
		else
			j++;
	}
	return ans;
}

int main()
{
	optimizeIO();
	int n, w;
	cin >> n >> w;
	vector<long long> tmp(n);
	for (int i = 0; i < n; i++)
		cin >> tmp[i];
	for (int i = 1; i < n; i++)
		a.push_back(tmp[i] - tmp[i - 1]);
	tmp.resize(0); tmp.resize(w);
	for (int i = 0; i < w; i++)
		cin >> tmp[i];
	for (int i = 1; i < w; i++)
		b.push_back(tmp[i] - tmp[i - 1]);
	n--; w--;
	if (w) cout << kmp() << endl;
	else cout << n + 1 << endl;
	return 0;
}
