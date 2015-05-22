#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

set<pair<queue<int>, queue<int> > >vis;

bool check(queue<int> a, queue<int> b)
{
	pair<queue<int>, queue<int> > tmp = make_pair(a, b);
	if (vis.find(tmp) != vis.end())
		return true;
	vis.insert(tmp);
	return false;
}

int main()
{
	optimizeIO();
	int n, k1, k2, v;
	queue<int> one, two;
	cin >> n >> k1;
	for (int i = 0; i < k1; i++)
	{
		cin >> v;
		one.push(v);
	}
	cin >> k2;
	for (int i = 0; i < k2; i++)
	{
		cin >> v;
		two.push(v);
	}
	int cnt = 0;
	bool damn = false;
	while (not one.empty() and not two.empty() and not damn)
	{
		damn = check(one, two);
		if (damn)
			break;
		int a = one.front();
		int b = two.front();
		one.pop(), two.pop();
		if (a > b)
		{
			one.push(b);
			one.push(a);
		}
		else
		{
			two.push(a);
			two.push(b);
		}
		cnt++;
	}
	if (damn)
		cout << "-1\n";
	else
	{
		cout << cnt << ' ';
		if (one.empty()) cout << 2 << endl;
		else cout << 1 << endl;
	}
	return 0;
}
