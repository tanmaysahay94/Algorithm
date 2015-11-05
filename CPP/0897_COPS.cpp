#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		int M, x, y;
		cin >> M >> x >> y;
		vector<int> safe(101, 1);
		for (int i = 0; i < M; i++)
		{
			int h;
			cin >> h;
			for (int j = h; j <= min(100, h + (x*y)); j++)
				safe[j] = 0;
			for (int j = h; j >= max(1, h - (x*y)); j--)
				safe[j] = 0;
		}
		int cnt = 0;
		for (int i = 1; i < 101; i++)
			cnt += safe[i];
		cout << cnt << '\n';
	}
	return 0;
}
