#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1), vis(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	int cnt(0), num(0);
	while (num < n)
	{
		if (cnt & 1)
		{
			for (int i = n; i >= 1; i--)
				if (not vis[i] and num >= v[i])
					vis[i] = true, num++;
			if (num < n)
				cnt++;
		}
		else
		{
			for (int i = 1; i <= n; i++)
				if (not vis[i] and num >= v[i])
					vis[i] = true, num++;
			if (num < n)
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
