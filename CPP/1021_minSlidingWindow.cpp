#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	deque<int> D;
	int i;
	for (i = 0; i + 1 < k; i++)
	{
		while (D.size() and v[i] < v[D.back()])
			D.pop_back();
		D.push_back(i);
	}
	vector<int> sol;
	for (; i < n; i++)
	{
		while (D.size() and v[i] < v[D.back()])
			D.pop_back();
		while (D.size() and i - D.front() >= k)
			D.pop_front();
		D.push_back(i);
		sol.push_back(v[D.front()]);
	}
	for (auto s: sol)
		cout << s << ' ';
	return 0;
}
