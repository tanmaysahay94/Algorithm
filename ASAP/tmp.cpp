#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct node
{
	int a, b;
	node (int aa, int bb)
	{
		a = aa;
		b = bb;
	}
	bool operator <(const node& foo) const
	{
		if (a == foo.a)
			return b > foo.b;
		return a > foo.a;
	}
};

int main()
{
	optimizeIO();
	priority_queue<node, vector<node> > pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		pq.push(node(a, b));
	}
	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();
		cout << tmp.a << ' ' << tmp.b << endl;
	}
	return 0;
}
