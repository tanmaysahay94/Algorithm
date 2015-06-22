#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;
LL n, k;

LL f(vector<LL>& b, vector<LL>& g)
{
	LL ans = 0;
	LL curr = 0;
	for (int i = 0; i < n and curr < n; i++)
	{
		if (g[curr] <= b[i])
		{
			while (curr < n and abs(b[i] - g[curr]) > k)
				curr++;
			if (curr < n)
			{
				ans++;
				curr++;
			}
		}
		else
		{
			if (curr < n and abs(b[i] - g[curr]) <= k)
			{
				ans++;
				curr++;
			}
		}
	}
	return ans;
}

LL fr(vector<LL>& b, vector<LL>& g)
{
	LL ans = 0;
	LL curr = 0;
	for (int i = 0; i < n and curr < n; i++)
	{
		if (g[curr] >= b[i])
		{
			while (curr < n and abs(b[i] - g[curr]) > k)
				curr++;
			if (curr < n)
			{
				ans++;
				curr++;
			}
		}
		else
		{
			if (curr < n and abs(b[i] - g[curr]) <= k)
			{
				ans++;
				curr++;
			}
		}
	}
	return ans;
}

int main()
{
	optimizeIO();
	cin >> n >> k;
	vector<LL> b(n), g(n);
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> g[i];
	sort(b.begin(), b.end());
	sort(g.begin(), g.end());
	int i = 0, j = 0, ans = 0;
	while (i < n)
	{
		while (j < n)
		{
			if (b[i] - g[j] <= k)
			{
				if (b[i] - g[j] >= -k)
				{
					ans++;
					j++;
				}
				break;
			}
			j++;
		}
		i++;
	}
	cout << ans;
	return 0;
}
