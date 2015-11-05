#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> hor(n), ver(n);
	n *= n;
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (hor[a] == 0 and ver[b] == 0)
		{
			hor[a] = ver[b] = 1;
			ans.push_back(i + 1);
		}
	}
	for (auto a: ans)
		cout << a << ' ';
	return 0;
}
