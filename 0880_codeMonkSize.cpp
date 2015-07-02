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
		int e;
		cin >> e;
		set<int> s;
		for (int i = 0; i < e; i++)
		{
			int x, y;
			cin >> x >> y;
			s.insert(x);
			s.insert(y);
		}
		cout << s.size() << '\n';
	}
	return 0;
}
